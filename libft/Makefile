NAME = libft.a

CC = gcc

SRCS_DIR = srcs/

SRCS = ft_strnstr.c ft_isdigit.c ft_putstr_fd.c ft_strlcpy.c ft_strlen.c ft_memcmp.c \
ft_putnbr_fd.c ft_strchr.c ft_striteri.c ft_bzero.c ft_strjoin.c ft_isascii.c \
ft_memcpy.c ft_isprint.c ft_putendl_fd.c ft_toupper.c ft_split.c ft_isalpha.c \
ft_memchr.c ft_putchar_fd.c ft_memset.c ft_substr.c ft_strncmp.c ft_strmapi.c \
ft_strtrim.c ft_memmove.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_atoi.c \
ft_isalnum.c ft_itoa.c ft_tolower.c ft_strrchr.c check_flags.c ft_printf.c print_i.c print_p.c \
print_str.c print_u.c print_x.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c get_next_line.c

# SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

# BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
# ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

# BONUS := $(addprefix $(SRCS_DIR), $(BONUS_FIL))

HEADER = ./includes/

CFLAGS = -Wall -Wextra -Werror -std=c99

OPTION = -I $(HEADER)

OBJS = $(SRCS:.c=.o)

BOBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)

#$(OBJS): $(SRCS)
%.o: %.c 
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

# bonus: $(OBJS) $(BOBJS)
# 	@ar -rc $(NAME) $(BOBJS) $(OBJS)

clean:
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
