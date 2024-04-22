#include "minishell.h"

void open_fd(t_token *token) {
  int i;

  i = -1;
  while (token->file && token->file[++i]) {
    if (ft_strncmp(token->file[i], "inn", 3) == 0)
      ft_open(token, ft_strdup(token->file[i] + 3), IN);
    else if (ft_strncmp(token->file[i], "heredoc", 7) == 0)
      ft_open(token, ft_strdup(token->file[i]), HEREDOC);
    else if (ft_strncmp(token->file[i], "app", 3) == 0)
      ft_open(token, ft_strdup(token->file[i] + 3), APPEND);
    else if (ft_strncmp(token->file[i], "out", 3) == 0)
      ft_open(token, ft_strdup(token->file[i] + 3), OUT);
  }
  if (token->in_fd != -69) {
    ft_dup2("infile", token->in_fd, STDIN_FILENO);
    close(token->in_fd);
  }
  if (token->out_fd != -69) {
    ft_dup2("outfile", token->out_fd, STDOUT_FILENO);
    close(token->out_fd);
  }
}

void ft_open(t_token *token, char *filename, t_rdr type) {
  if (type == IN || type == HEREDOC) {
    if (token->in_fd != -69)
      close(token->in_fd);
    token->in_fd = open(filename, O_RDONLY);
    if (token->in_fd == -1)
      exit(error(filename, "No such file or directory"));
  } else if (type == APPEND || type == OUT) {
    if (token->out_fd != -69)
      close(token->out_fd);
    if (type == APPEND) {
      token->out_fd = open(filename, O_CREAT | O_APPEND | O_RDWR,
                           S_IRWXU | S_IRGRP | S_IROTH);
    } else {
      token->out_fd = open(filename, O_CREAT | O_TRUNC | O_RDWR,
                           S_IRWXU | S_IRGRP | S_IROTH);
    }
    if (token->out_fd == -1)
      exit(error(filename, "No such file or directory"));
  }
  free(filename);
}

void ft_dup2(char *str, int oldfd, int newfd) {
  int res;

  res = dup2(oldfd, newfd);
  if (res == -1) {
    write(2, str, ft_strlen(str));
    write(2, ": ", 2);
    write(2, "dup2 failed", 11);
    exit(1);
  }
}

void child_dup(t_token *current, int pipe_fd[2][2]) {
  if (current->next)
    ft_dup2(current->raw, pipe_fd[0][1], STDOUT_FILENO);
  if (current->prev)
    ft_dup2(current->raw, pipe_fd[1][0], STDIN_FILENO);
  close(pipe_fd[0][0]);
  if (current->prev)
    close(pipe_fd[1][0]);
  close(pipe_fd[0][1]);
}

void main_pipes(t_token *current, int pipe_fd[2][2]) {
  if (current->prev) {
    close(pipe_fd[1][0]);
  }
  if (current->next) {
    pipe_fd[1][0] = pipe_fd[0][0];
  }
  close(pipe_fd[0][1]);
  if (!current->next) {
    close(pipe_fd[0][0]);
  }
}
