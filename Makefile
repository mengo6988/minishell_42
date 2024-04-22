NAME = minishell

CC = gcc

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS_FIL = test.c helper.c env_arr.c history.c  token_test.c token_utils.c token_expand.c token_class.c export.c cd.c unset.c init.c readline.c helper1.c echo.c  redirect.c heredoc.c reset.c fd.c execute.c signal.c
# execute.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FIL))

HEADER = ./includes/

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -fsanitize=address -g3

INCLUDES = -I$(HEADER) -I$(LIBFT_DIR) -I/opt/homebrew/opt/readline/include

LIBFT = $(LIBFT_DIR)libft.a

LIBFT_DIR = libft

LIBRARIES =  -L$(LIBFT_DIR) -lft  -L/opt/homebrew/opt/readline/lib -lreadline
# 

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FIL:.c=.o))

all: pre $(NAME)

pre:
	export LDFLAGS="-L/opt/homebrew/opt/readline/lib" CPPFLAGS="-I/opt/homebrew/opt/readline/include"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@


$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

format:
	@$(foreach file, $(wildcard $(SRCS_DIR)*), c_formatter_42 $(file);)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)

re: fclean all 


.PHONY: all clean fclean re format

# @echo -e "\033[2J\033[1;1H"
# 	@echo -e "\033[9A\033[K"
# 	@tput clear || printf "\033c"
