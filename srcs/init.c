#include "libft.h"
#include "minishell.h"

void ms_init(t_ms *ms, char **env) {
  ms->token = NULL;
  env_init(env, ms);
  ms->input = NULL;
  ms->previous_input = NULL;
  ms->latest_err = 0;
  ms->exit = FALSE;
  func_list_init(ms);
  func_ptr_init(ms);
  get_path(ms);
}

void func_list_init(t_ms *ms) {
  char **ls;

  ls = ft_malloc(sizeof(char *) * 8);
  ls[0] = ft_strdup("echo");
  ls[1] = ft_strdup("cd");
  ls[2] = ft_strdup("pwd");
  ls[3] = ft_strdup("export");
  ls[4] = ft_strdup("unset");
  ls[5] = ft_strdup("env");
  ls[6] = ft_strdup("exit");
  ls[7] = NULL;
  ms->function_list = ls;
}

void func_ptr_init(t_ms *ms) {
  ms->function_ptr[0] = echo;
  ms->function_ptr[1] = cd;
  ms->function_ptr[2] = pwd;
  ms->function_ptr[3] = export;
  ms->function_ptr[4] = unset;
  ms->function_ptr[5] = env;
  ms->function_ptr[6] = ft_exit;
}

void get_path(t_ms *ms) {
  char *value;
  char **res;
  char **temp;
  int i;

  value = get_env(ms, "PATH");
  temp = ft_split(value, ':');
  i = 0;
  while (temp[i])
    i++;
  res = ft_calloc(i + 2, sizeof(char *));
  i = -1;
  while (temp[++i])
    res[i] = ft_strjoin(temp[i], "/");
  res[i] = ft_strdup("");
  free_double_array(temp);
  if (ms->path)
    free_double_array(ms->path);
  ms->path = res;
}

// WARN: while path[i], join_path(path[i], cmd)
