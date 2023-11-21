NAME		= push_swap
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror
INCLUDES	= includes/
SRCS		= main.c
OBJS		= ${addprefix obj/, ${SRCS:.c=.o}}

$(NAME): $(OBJS)
	@echo '* Assembling $@'
	@$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.c
	@echo '- Compiling $<'
	@$(CC) $(CCFLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

clean:
	@echo '! Removing obj files'
	@rm -f $(OBJS)

fclean: clean
	@echo '! Removing $(NAME)'
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette ${SRCS} | grep 'Error'

.PHONY: all clean fclean re
