#include "minishell.h"

int echo(t_ms *ms, char **args) {
  int flag;

  if (!args[1][0] && !args[2]) {
    ft_printf("\n");
    return (0);
  }
  flag = 1;
  while (ft_strcmp(args[flag], "-n") == 0)
    flag++;
  // printf("flag = %i\n", flag);
  echo_print(args, flag);
  return (0);
}

void echo_print(char **args, int flag) {
  int i;
  char *str;

  i = flag;
  while (args[i]) {
    if (args[i][0] == '\'')
      str = ft_strtrim(args[i], "'");
    else if (args[i][0] == '"')
      str = ft_strtrim(args[i], "\"");
    else
      str = ft_strdup(args[i]);
    if (i == flag && args[i][0] == ' ')
      ft_printf("%s", str + 1);
    else
      ft_printf("%s", str);
    // if ((args[i + 1] && args[i + 1][0] == '\'') ||
    //     (args[i + 1] && args[i + 1][0] != '"'))
    //   ft_printf(" ");
    free(str);
    i++;
  }
  if (flag <= 1)
    ft_printf("\n");
  return;
}
