#include "minishell.h"

void *ft_malloc(size_t size) {
  void *res;

  // printf("size = %zu\n", size);
  res = malloc(size);
  if (!res) {
    ft_putstr_fd("Malloc fail\n", 2);
    exit(1);
  }
  return (res);
}

char *ft_strndup(const char *s, int len) {
  char *res;
  int i;

  res = ft_calloc(sizeof(char), (len + 1));
  if (!res) {
    ft_putstr_fd("Malloc fail strndup\n", 2);
    exit(1);
  }
  i = -1;
  while (++i < len && s[i])
    res[i] = s[i];
  res[i] = '\0';
  return (res);
}

int ft_strcmp(const char *s1, const char *s2) {
  int i;

  i = -1;
  while (s1[++i] && s2[i]) {
    if (s1[i] != s2[i])
      break;
  }
  return (s1[i] - s2[i]);
}

char *ft_strncpy(char *dst, char *src, size_t len) {
  size_t i;

  if (len <= 0)
    return dst;
  i = -1;
  while (src[++i] && i < len) {
    dst[i] = src[i];
  }
  while (i < len)
    dst[i++] = 0;
  return (dst);
}

char *add_quotes(char *s) {
  char *res;

  res = ft_calloc(sizeof(char), ft_strlen(s) + 2);
  res[0] = '"';
  res[ft_strlen(s) + 1] = '"';
  ft_strncpy(res + 1, s, ft_strlen(s));
  return (res);
}
