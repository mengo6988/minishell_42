#include "libft.h"
#include "minishell.h"

void export_to_env(t_ms *ms, char *s) {
  int i;
  char *key;

  i = 0;
  while (s[i] && s[i] != '=')
    i++;
  if (!s[i]) {
    // insert_new_env(ms, s);
    return;
  }
  key = ft_strndup(s, i);
  i = find_key(ms->env, key);
  free(key);
  if (i == -1) {
    // printf("not found = %s\n", s);
    insert_new_env(ms, s);
  } else {
    // printf("found = %s\n", s);
    replace_env(ms, s, i);
  }
}

void pre_export(char **args) {
  int i;

  i = -1;
  while (args[++i]) {
    if (args[i][ft_strlen(args[i]) - 1] == '=' && args[i + 1]) {
      args[i] = joinf(args[i], args[i + 1]);
    }
  }
}

int export(t_ms *ms, char **args) {
  int i;

  if (!args[1]) {
    i = -1;
    while (ms->env[++i])
      ft_printf("declare -x %s\n", ms->env[i]);
  } else {
    pre_export(args);
    i = 0;
    while (args[++i]) {
      printf("args: %s\n", args[i]);
      export_to_env(ms, args[i]);
    }
  }
  return (0);
}
