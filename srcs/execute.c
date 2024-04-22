#include "libft.h"
#include "mini_structs.h"
#include "minishell.h"

// TODO: get env paths -> run it through builtins first, builtins would be done
// on parent process as some of them will affect the env list -> run on execve,
// if close then it ran well, if all dont run then command not found error
// piping will be done individually i think, so before execve... all the
// heredocs will run first too... and also everything before infile/heredoc will
// not be run at all

void child_node(t_ms *ms, t_token *current, int pipe_fd[2][2]) {
  // TODO: duppings
  if (pipe_fd)
    child_dup(current, pipe_fd);
  open_fd(current);
  if (current->builtin != NONE)
    exit(ms->function_ptr[current->builtin](ms, current->args));
  else if (current->builtin == NONE && current->raw[0] != '\0')
    run_execve(ms, current->args);
}

// TODO: check what file
// based on which file, if theres an fd open, close that fd and open a new
// one
// WARN: dup the thing into stdin and out as well???

void run_execve(t_ms *ms, char **args) {
  int i;
  char *filepath;
  int res;

  i = -1;
  // for (int j = 0; args[j]; j++) {
  //   write(2, "args: ", 6);
  //   write(2, args[j], ft_strlen(args[j]));
  //   write(2, "\n", 1);
  // }
  reset_signal();
  if (!ms->path) {
    error(args[0], "No such file or directory");
    exit(127);
  }
  while (ms->path[++i]) {
    filepath = ft_strjoin(ms->path[i], args[0]);
    res = execve(filepath, args, ms->env);
    free(filepath);
    if (res != -1)
      break;
  }
  if (!ms->path[i]) {
    error(args[0], "command not found");
    exit(127);
  }
}

int multicmd(t_ms *ms, pid_t *pid) {
  t_token *current;
  int i;
  int pipe_fd[2][2];

  current = ms->token;
  i = 0;
  while (current) {
    if (pipe(pipe_fd[0]) == -1)
      exit(error(current->raw, "pipe failed"));
    pid[i] = fork();
    if (pid[i++] == 0) {
      child_node(ms, current, pipe_fd);
      break;
    } else {
      main_pipes(current, pipe_fd);
      current = current->next;
    }
  }
  return (-1);
}

pid_t *pid_init(t_token *token) {
  int i;
  pid_t *res;

  i = 0;
  while (token) {
    i++;
    token = token->next;
  }
  res = ft_calloc(i, sizeof(pid_t));
  return (res);
}

// WARN: cd export unset exit should be done on main process
int singlecmd(t_ms *ms, pid_t *pid) {
  t_token *token;
  int res;

  token = ms->token;
  if (token->builtin == CD || token->builtin == UNSET ||
      token->builtin == EXPORT || token->builtin == EXIT)
    res = ms->function_ptr[token->builtin](ms, token->args);
  else {
    pid[0] = fork();
    if (!pid[0])
      child_node(ms, token, NULL);
    res = -1;
  }
  return (res);
}

void execution(t_ms *ms) {
  pid_t *pid;
  int res;

  pid = pid_init(ms->token);
  if (!ms->token->next)
    res = singlecmd(ms, pid);
  else
    res = multicmd(ms, pid);
  if (res == -1)
    wait_child(ms, pid);
  else
    ms->latest_err = res;
  free(pid);
}

void wait_child(t_ms *ms, pid_t *pid) {
  int i;
  int status;
  int count;
  t_token *current;

  i = -1;
  count = -1;
  current = ms->token;
  while (current && ++count >= 0)
    current = current->next;
  while (++i <= count) {
    if (waitpid(pid[i], &status, 0) == -1)
      perror("waitpid failed");
    if (WIFEXITED(status))
      ms->latest_err = WEXITSTATUS(status);
  }
  // ft_printf("wait dones\n");
}
