#include "minishell.h"

void print_current(t_token *head) {
  t_token *current;

  if (!head) {
    ft_printf("nothing here\n");
    return;
  }
  char *list[11] = {"CMD",     "ARGS",    "REDIRECTION", "PIPE",
                    "S_QUOTE", "D_QUOTE", "FILEPATH"};
  char *rdr[5] = {"NONE", "IN", "OUT", "APP", "HERE"};
  current = head;
  if (current) {
    ft_printf("---------------TOKEN------------\n");
    ft_printf("%i \n", current->i);
    if (current->raw)
      ft_printf("raw = %s\n", current->raw);
    else
      ft_printf("null\n");
    ft_printf("type = %s\n", list[current->type]);
    ft_printf("rdr = %s\n", rdr[current->rdr_type]);
    ft_printf("args = ");
    if (current->args) {
      for (int i = 0; current->args[i]; i++)
        ft_printf("%s, ", current->args[i]);

    } else
      ft_printf("null");
    ft_printf("\n");

    ft_printf("file = ");
    if (current->file) {
      for (int i = 0; current->file[i]; i++)
        ft_printf("%s, ", current->file[i]);

    } else
      ft_printf("null");
    ft_printf("\n");
    if (current->next)
      printf("next\n");
    else
      printf("no next\n");
    if (current->prev)
      printf("prev\n");
    else
      printf("no prev\n");
  }
  printf("\n");
}

void print_token(t_token *head) {
  t_token *current;

  if (!head) {
    ft_printf("nothing here\n");
    return;
  }
  char *list[11] = {"CMD",     "ARGS",    "REDIRECTION", "PIPE",
                    "S_QUOTE", "D_QUOTE", "FILEPATH"};
  char *rdr[5] = {"NONE", "IN", "OUT", "APP", "HERE"};
  current = head;
  while (current) {
    ft_printf("---------------TOKEN------------\n");
    ft_printf("%i \n", current->i);
    if (current->raw)
      ft_printf("raw = %s\n", current->raw);
    else
      ft_printf("null\n");
    ft_printf("type = %s\n", list[current->type]);
    ft_printf("rdr = %s\n", rdr[current->rdr_type]);
    ft_printf("args = ");
    if (current->args) {
      for (int i = 0; current->args[i]; i++)
        ft_printf("%s, ", current->args[i]);

    } else
      ft_printf("null");
    ft_printf("\n");

    ft_printf("file = ");
    if (current->file) {
      for (int i = 0; current->file[i]; i++)
        ft_printf("%s, ", current->file[i]);

    } else
      ft_printf("null");
    ft_printf("\n");
    if (current->next)
      printf("next\n");
    else
      printf("no next\n");
    if (current->prev)
      printf("prev\n");
    else
      printf("no prev\n");
    current = current->next;
  }
}

void reset_ms(t_ms *ms) {
  t_token *token;

  token = ms->token;
  token_deleteall(&token);
  ms->token = NULL;
}

int main(int ac, char **av, char **env) {
  t_ms ms;
  // char *test;

  (void)ac;
  (void)av;
  env_init(env, &ms);
  ms_init(&ms, env);
  // print_env(&ms);
  ms.token = NULL;
  // for (int i = 0; ms.env[i]; i++)
  //   ft_printf("%s\n", ms.env[i]);
  while (1) {
    signal_init();
    ms_readline(&ms);
    if (!ms.input || ms.input[0] == '\0')
      continue;
    execution(&ms);
    rm_heredoc(&ms);
    token_deleteall(&ms.token);
    free(ms.input);
    ms.input = NULL;
    reset_ms(&ms);
  }
  return (0);
}

// TODO: Parsing/tokenizing the input...
// TODO: Handling the pipes, open fd and closing the unnecasarry ones
// 	heredoc is a must as well...
//
// TODO: Checking the access/if function/cmd is available, then execve it
// TODO: Reset the arguments to wait for next input

// FIX: Handling the signals
// exit status has to be right

// WARN: echo with -n option
// only takes -n once
// cd with relative/absolute path
// pwd with no options
// export with no option
// unset with no options
// env with no options/arguments
// exit with no options
//
// HACK: echo, pwd, env can use the builtin scripts
//
// NOTE: export dones?
