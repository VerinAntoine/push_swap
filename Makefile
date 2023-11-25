NAME		= push_swap
CC			= cc
CCFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= includes/
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= $(LIBFT)
OBJ_DIR		= obj

SRCS		= $(addprefix src/, main.c ps_parser.c ps_operation.c ps_operation_extra.c\
				ps_sort.c)
STACK_SRCS	= $(addprefix ft_stack/, stack_add.c stack_last.c stack_print.c\
				stack_swap.c stack_free.c stack_rotate.c stack_rvs_rotate.c stack_push.c\
				stack_is_ordered.c stack_max.c)
OBJS		= ${addprefix $(OBJ_DIR)/, ${SRCS:.c=.o} ${STACK_SRCS:.c=.o}}

$(NAME): $(OBJS) $(LIBS)
	@echo '* Assembling $@'
	@$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p obj
	@mkdir -p obj/src
	@mkdir -p obj/ft_stack
	@echo '- Compiling $<'
	@$(CC) $(CCFLAGS) -c $< -o $@ -I $(INCLUDES)

$(LIBFT):
	@echo '* Making libft'
	@make -C $(LIBFT_DIR)

relib:
	@echo '* Remaking libft'
	@make re -C $(LIBFT_DIR)

cleanlib:
	@echo '* Cleaning libft'
	@make clean -C $(LIBFT_DIR)

fcleanlib:
	@echo '* Cleaning libft'
	@make fclean -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@echo '! Removing obj files'
	@rm -f $(OBJS)

fclean: clean
	@echo '! Removing $(NAME)'
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	norminette ${SRCS} ${STACK_SRCS} | grep 'Error'

.PHONY: all clean fclean re
