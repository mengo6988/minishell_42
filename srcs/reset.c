#include "minishell.h"

void rm_heredoc(t_ms *ms) {
  t_token *token;
  int i;

  token = ms->token;
  while (token) {
    if (token->file) {
      i = -1;
      while (token->file[++i]) {
        if (ft_strncmp(token->file[i], "heredoc", 7) == 0)
          unlink(token->file[i]);
      }
    }
    token = token->next;
  }
}
