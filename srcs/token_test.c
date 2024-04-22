#include "mini_structs.h"
#include "minishell.h"

void tokenize(t_ms *ms) {
  int i;

  i = 0;
  while (ms->input[i]) {
    if (ms->input[i] == ' ')
      i++;
    else if (ms->input[i] == '>')
      tk_redir_out(ms, &i);
    else if (ms->input[i] == '<')
      tk_redir_in(ms, &i);
    else if (ms->input[i] == '|')
      tk_pipe(ms, &i);
    else if (ms->input[i] == '"' || ms->input[i] == '\'')
      tk_quotes(ms, &i);
    else
      tk_word(ms, &i);
  }
  // TODO: LEXICAL ANALYSIS
}

void tk_redir_in(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  if (ms->input[*i + 1] == '<') {
    new->type = REDIRECTION;
    new->raw = ft_strndup(ms->input + *i, 2);
    *i += 2;
    new->rdr_type = HEREDOC;
  } else {
    new->type = REDIRECTION;
    new->raw = ft_strndup(ms->input + *i, 1);
    new->rdr_type = IN;
    (*i)++;
  }
  new->is_quotes = FALSE;
  new->args = NULL;
  token_add_back(&ms->token, new);
}

void tk_redir_out(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  if (ms->input[*i + 1] == '>') {
    new->type = REDIRECTION;
    new->raw = ft_strndup(ms->input + *i, 2);
    new->rdr_type = APPEND;
    (*i) += 2;
  } else {
    new->type = REDIRECTION;
    new->raw = ft_strndup(ms->input + *i, 1);
    new->rdr_type = OUT;
    (*i)++;
  }
  new->args = NULL;
  new->is_quotes = FALSE;
  token_add_back(&ms->token, new);
}

void tk_pipe(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  new->type = PIPE;
  new->raw = ft_strndup(ms->input + *i, 1);
  new->rdr_type = 0;
  new->is_quotes = FALSE;
  new->args = NULL;
  token_add_back(&ms->token, new);
  (*i)++;
}

void tk_quotes(t_ms *ms, int *i) {
  t_token *new;
  char *str;
  int j;

  new = token_new();
  j = 1;
  while (ms->input[*i + j] && ms->input[*i + j] != ms->input[*i])
    j++;
  if (ms->input[*i] == '\'')
    new->type = S_QUOTE;
  else
    new->type = D_QUOTE;
  if (ms->input[*i - 1] == ' ')
    new->raw = ft_strdup(" ");
  else
    new->raw = ft_strdup("");
  str = ft_strndup(ms->input + ++(*i), j);
  new->raw = joinf(new->raw, str);
  new->is_quotes = TRUE;
  token_add_back(&ms->token, new);
  (*i) += j;
}

void tk_word(t_ms *ms, int *i) {
  int j;
  t_token *new;

  new = token_new();
  j = 0;
  while (ms->input[*i + j] && ms->input[*i + j] != ' ' &&
         ms->input[*i + j] != '>' && ms->input[*i + j] != '<' &&
         ms->input[*i + j] != '|' && ms->input[*i + j] != '"' &&
         ms->input[*i + j] != '\'')
    j++;
  new->raw = ft_strndup(ms->input + *i, j);
  new->type = CMD;
  new->rdr_type = 0;
  new->is_quotes = FALSE;
  new->args = NULL;
  token_add_back(&ms->token, new);
  (*i) += j;
}
