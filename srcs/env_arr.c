#include "libft.h"
#include "minishell.h"

void env_init(char **env, t_ms *ms) {
  char **local_env;
  int i;

  i = 0;
  while (env[i])
    i++;
  local_env = malloc(sizeof(char *) * (i + 1));
  local_env[i] = NULL;
  i = -1;
  while (env[++i]) {
    local_env[i] = ft_strdup(env[i]);
  }
  ms->env = local_env;
}

int find_key(char **env, char *s) {
  int i;

  i = 0;
  while (env[i]) {
    if (ft_strncmp(env[i], s, ft_strlen(s)) == 0)
      return (i);
    i++;
  }
  return (-1);
}

void insert_new_env(t_ms *ms, char *s) {
  char **new_env;
  int i;

  i = 0;
  while (ms->env[i])
    i++;
  new_env = malloc(sizeof(char *) * (i + 2));
  i = -1;
  while (ms->env[++i]) {
    new_env[i] = ft_strdup(ms->env[i]);
  }
  new_env[i++] = ft_strdup(s);
  new_env[i] = NULL;
  delete_env_arr(ms->env);
  ms->env = new_env;
  return;
}

void replace_env(t_ms *ms, char *s, int i) {
  char *res;

  res = ft_strdup(s);
  free(ms->env[i]);
  ms->env[i] = res;
  return;
}

char *get_env(t_ms *ms, char *s) {
  char *res;
  int i;

  if (s[0] == '?') {
    res = ft_itoa(ms->latest_err);
    ft_printf("res = %s");
    return (res);
  }
  i = find_key(ms->env, s);
  if (i >= 0) {
    res = ft_strdup(ms->env[i] + ft_strlen(s) + 1);
    return (res);
  } else {
    res = ft_calloc(sizeof(char), 1);
  }
  return (res);
}
