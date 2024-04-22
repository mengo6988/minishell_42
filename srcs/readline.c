#include "mini_structs.h"
#include "minishell.h"

void ms_readline(t_ms *ms) {
  ms->input = readline("minishell > ");
  if (ms->input == NULL) {
    printf("\rexit\n");
    // rl_replace_line("minishell > exit\n", 0);
    exit(ms->latest_err);
  }
  if (ms->input[0] == '\0')
    return;
  handle_unclosed(ms);
  ms_addhistory(ms);
  handle_dollars(ms, &ms->input, FALSE);
  tokenize(ms);
  token_rmquotes(ms);
  token_settype(ms);
  set_builtin(ms);
  combine_tokens(ms);
  pre_rdr(ms);
  handle_rdr(ms);
  delete_rdr(ms);
  handle_heredocs(ms);
  print_token(ms->token);
}
// while (current) {
//   if (current->type != S_QUOTE)
//     expand_dollars(ms, &current->raw);
//   current = current->next;
// }
// current = ms->token;

int count_char(char *s, char c) {
  int i;
  int count;

  i = -1;
  count = 0;
  while (s[++i]) {
    if (s[i] == c)
      count++;
  }
  return (count);
}

void handle_unclosed(t_ms *ms) {
  char *res;

  res = ft_strdup("");
  while (count_char(ms->input, '"') % 2 || count_char(ms->input, '\'') % 2 ||
         ms->input[ft_strlen(ms->input) - 1] == '|') {
    res = readline(">");
    ms->input = joinf(ms->input, res);
    free(res);
  }
}
