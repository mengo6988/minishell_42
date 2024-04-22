#include "libft.h"
#include "minishell.h"

int unset(t_ms *ms, char **args) {
  int i;
  int j;
  char **new_env;

  i = find_key(ms->env, args[1]);
  if (i == -1)
    return (0);
  j = 0;
  while (ms->env[j])
    j++;
  new_env = ft_malloc(sizeof(char *) * j);
  j = -1;
  while (ms->env[++j] && j != i)
    new_env[j] = ft_strdup(ms->env[j]);
  while (ms->env[++j])
    new_env[i++] = ft_strdup(ms->env[j]);
  new_env[i] = NULL;
  ms->env = new_env;
  return (0);
}

int env(t_ms *ms, char **args) {
  int i;

  i = 0;
  while (args[i] && args[i][0] != '\0' && ft_strcmp(args[i], "env") == 0)
    i++;
  if (args[i]) {
    write(2, "env: ", 5);
    write(2, &args[i], ft_strlen(args[i]));
    write(2, ": No such file or directory\n", 28);
    return (127);
  }
  i = -1;
  while (ms->env[++i])
    if (ft_strrchr(ms->env[i], '='))
      ft_printf("%s\n", ms->env[i]);
  return (0);
}

void delete_env_arr(char **env) {
  int i;

  i = -1;
  while (env[++i])
    free(env[i]);
  free(env);
  return;
}
