#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// int main(int ac, char **av, char **env) {
//   pid_t pid;
//   char *cmd[] = {"env", NULL};
//   char *path = "/usr/bin/env";
//   char *custom[] = {"test=hello", "wow=no", NULL};
//
//   // pid = fork();
//   // if (pid == 0) {
//   //   execve(path, cmd, custom);
//   // } else {
//   //   waitpid(pid, NULL, 0);
//   // }
//   for (int i = 0; env[i]; i++) {
//     printf("%s\n", env[i]);
//   }
// }
//
int main() {
  char *outfile = "out";
  int fd = open(outfile, O_CREAT | O_RDWR);
  if (fd == -1)
    perror("fd error...\n");
  int new_fd;
  int rep_fd;
  new_fd = dup2(fd, STDOUT_FILENO);
  if (new_fd == 1)
    write(2, "1\n", 2);
  write(fd, "rofl", 4);
  write(new_fd, "omg", 3);
  write(2, "test", 4);
}
