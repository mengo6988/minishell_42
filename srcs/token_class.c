#include "mini_structs.h"
#include "minishell.h"

void token_rmquotes(t_ms *ms) {
  t_token *current;
  char *res;

  current = ms->token;
  while (current) {
    if (current->type == S_QUOTE) {
      current->type = CMD;
      res = ft_strtrim(current->raw, "'");
      free(current->raw);
      current->raw = res;
    } else if (current->type == D_QUOTE) {
      current->type = CMD;
      res = ft_strtrim(current->raw, "\"");
      free(current->raw);
      current->raw = res;
    }
    res = NULL;
    current = current->next;
  }
}

void token_settype(t_ms *ms) {
  t_token *current;
  int flag;

  current = ms->token;
  flag = 0;
  while (current) {
    if (current->type == CMD && flag == 0)
      flag = 1;
    else if (current->type == CMD && flag == 1)
      current->type = ARGS;
    else
      flag = 0;
    if (current->prev && current->prev->type == REDIRECTION) {
      current->type = ARGS;
      flag = 0;
    }
    current = current->next;
  }
}

// if first is CMD, until the next meta character, it will be args
// any CMD after redirection is ARGS for the redirection
// anything after pipe is a command

void set_builtin(t_ms *ms) {
  t_token *current;
  int i;

  current = ms->token;
  while (current) {
    if (current->type != CMD)
      current->builtin = NONE;
    i = 0;
    while (ms->function_list[i] &&
           ft_strcmp(current->raw, ms->function_list[i]))
      i++;
    current->builtin = i;
    current = current->next;
  }
}

void combine_tokens(t_ms *ms) {
  // TODO: combine the args and put them into their respective
  // cmd/pipes/redirect
  // FIX:THE STUPID QUOTES PUT BACK, ONLY IF COMMAND ITSELF IS ECHO
  t_token *current;
  t_token *temp;

  current = ms->token;
  while (current) {
    if (current->type != ARGS)
      add_args_to_cmd(&current);
    current = current->next;
  }
  current = ms->token;
  while (current) {
    if (current->type == ARGS) {
      temp = current;
      current = current->next;
      token_delete(temp);
    } else
      current = current->next;
  }
}

void add_args_to_cmd(t_token **token) {
  t_token *current;
  int i;
  int len;

  current = (*token)->next;
  len = 1;
  while (current && current->type == ARGS) {
    current = current->next;
    len++;
  }
  (*token)->args = ft_malloc(sizeof(char *) * (len + 2));
  i = -1;
  current = (*token);
  while (++i < len) {
    // if ((*token)->builtin == ECHO && current->is_quotes == TRUE)
    //   (*token)->args[i] = add_quotes(current->raw);
    // else
    (*token)->args[i] = ft_strdup(current->raw);
    // (*token)->args[i] = s;
    current = current->next;
  }
  (*token)->args[i] = NULL;
}
