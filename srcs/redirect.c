#include "libft.h"
#include "mini_structs.h"
#include "minishell.h"

void handle_rdr(t_ms *ms) {
  t_token *current;
  t_token *cmd;
  int flag;

  current = ms->token;
  cmd = get_cmd(current);
  while (current) {
    if (current->type == PIPE) {
      cmd = get_cmd(current);
      flag = 0;
    }
    if (current->rdr_type != 0 && current->rdr_type != HEREDOC && cmd)
      add_rdr(current, cmd);
    else if (current->rdr_type == HEREDOC && flag == 0 && cmd) {
      flag = 1;
      add_rdr(current, cmd);
    }
    current = current->next;
  }
}

t_token *get_cmd(t_token *current) {
  t_token *res;

  if (current->type == CMD)
    return (current);
  res = current->next;
  while (res && res->type != PIPE) {
    if (res->type == CMD)
      return (res);
    res = res->next;
  }
  return (NULL);
}

void add_rdr(t_token *current, t_token *cmd) {
  char *here;

  if (current->rdr_type == OUT)
    cmd->file = insert_2d_arr(cmd->file, ft_strjoin("out", current->args[1]));
  if (current->rdr_type == APPEND)
    cmd->file = insert_2d_arr(cmd->file, ft_strjoin("app", current->args[1]));
  if (current->rdr_type == IN)
    cmd->file = insert_2d_arr(cmd->file, ft_strjoin("inn", current->args[1]));
  if (current->rdr_type == HEREDOC) {
    here = heredoc_name_generator();
    cmd->file = insert_2d_arr(cmd->file, here);
  }
}

void delete_rdr(t_ms *ms) {
  t_token *current;
  t_token *temp;

  current = ms->token;
  while (current->rdr_type != 0 && current->rdr_type != HEREDOC) {
    temp = current;
    current = current->next;
    token_delete(temp);
    ms->token = current;
  }
  while (current) {
    if (current->rdr_type != 0 && current->rdr_type != HEREDOC) {
      temp = current;
      current = current->next;
      token_delete(temp);
    } else
      current = current->next;
  }
}

void pre_rdr(t_ms *ms) {
  t_token *current;
  t_token *temp;
  t_token *new;
  int flag;

  current = ms->token;
  temp = current;
  while (current) {
    if (current->type == CMD) {
      flag = 1;
    }
    if (current->type == PIPE && flag) {
      temp = current;
      flag = 0;
    } else if ((current->type == PIPE && !flag) || (!current->next && !flag)) {
      new = token_new();
      new->type = CMD;
      new->raw = ft_calloc(1, sizeof(char));
      new->builtin = NONE;
      token_insert(temp, new);
    }
    current = current->next;
  }
}

// TODO: HANDLE THE RDR
