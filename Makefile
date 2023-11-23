NAME		= push_swap
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= includes/
SRCS		= main.c
STACK_SRCS	= $(addprefix ft_stack/, ft_stk_add.c ft_stk_last.c ft_stk_print.c\
				ft_stk_swap.c ft_stk_free.c ft_stk_remove.c ft_stk_rotate.c\
				ft_stk_rvs_rotate.c ft_stk_push.c)
OBJS		= ${addprefix obj/, ${SRCS:.c=.o} ${STACK_SRCS:.c=.o}}

$(NAME): $(OBJS) libft/libft.a
	@echo '* Assembling $@'
	@$(CC) $(CCFLAGS) $(OBJS) libft/libft.a -o $(NAME)

obj/%.o: %.c
	@mkdir -p obj
	@mkdir -p obj/ft_stack
	@echo '- Compiling $<'
	@$(CC) $(CCFLAGS) -c $< -o $@ -I $(INCLUDES)

libft/libft.a:
	@echo '* Making libft'
	@make -C libft

relib:
	@echo '* Remaking libft'
	@make re -C libft

cleanlib:
	@echo '* Cleaning libft'
	@make clean -C libft

fcleanlib:
	@echo '* Cleaning libft'
	@make fclean -C libft

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
