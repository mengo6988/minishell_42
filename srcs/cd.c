#include "minishell.h"
#include <stdint.h>

int cd(t_ms *ms, char **args) {
  char *path;
  if (!args[1] || args[1][0] == '~') {
    path = get_env(ms, "HOME");
    if (!path)
      perror("minishell: cd: HOME not set");
  } else if (args[1][0] == '-' && ft_strlen(args[1]) == 1) {
    path = get_env(ms, "OLDPWD");
    if (!path)
      perror("minishell: cd: OLDPWD not set");
  } else
    path = ft_strdup(args[1]);
  if (chdir(path) == -1) {
    perror(path);
  } else
    replace_pwd(ms);
  return (0);
}

// TODO: builtin_cd
// if cd -: swaps oldpwd and pwd
// if cd no args: goes to HOME
// sets pwd and oldpwd and goes to argument

void replace_pwd(t_ms *ms) {
  char *key;
  char *value;

  value = get_env(ms, "PWD");
  key = ft_strdup("OLDPWD=");

  key = joinf(key, value);
  export_to_env(ms, key);
  free(value);
  free(key);
  value = getcwd(NULL, 0);
  key = ft_strdup("PWD=");
  key = joinf(key, value);
  export_to_env(ms, key);
  free(key);
  return;
}

// TODO: replace oldpwd with pwd
// getcwd and replace pwd with it

int ft_exit(t_ms *ms, char **args) {
  uint8_t len;

  len = 0;
  while (args[len])
    len++;
  if (len > 2) {
    printf("minishell: exit: too many arguments\n");
    // TODO: set return value to 1
    exit(1);
  } else if (len == 1) {
    printf("exit\n\n");
    exit(ms->latest_err);
  }
  if (!ft_isnum(args[1])) {
    printf("minishell: exit: %s: numeric argument required\n", args[1]);
    // TODO: set return value to 255
    // set exit to true
    exit(255);
  } else {
    len = ft_atoi(args[1]);
    // TODO:set return value to arguments
    // set exit to true
    exit(len);
  }
}

int pwd(t_ms *ms, char **args) {
  char *pwd;

  (void)ms;
  (void)args;
  pwd = getcwd(NULL, 0);
  ft_printf("%s\n", pwd);
  free(pwd);
  return (0);
}
