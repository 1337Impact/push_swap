NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

LST_PATH = lst_manipulate

SRCS = $(LST_PATH)/ft_lstnew.c \
		$(LST_PATH)/ft_lstadd_front.c \
		$(LST_PATH)/ft_lstsize.c \
		$(LST_PATH)/ft_lstlast.c \
		$(LST_PATH)/ft_lstadd_back.c \
		$(LST_PATH)/ft_lstclear.c \
		push_swap.c \
		actions.c \
		utils.c \
		sort_stack.c \
		radix_sort.c \
		check_stack.c

B_SRCS = $(LST_PATH)/ft_lstnew.c \
		$(LST_PATH)/ft_lstadd_front.c \
		$(LST_PATH)/ft_lstsize.c \
		$(LST_PATH)/ft_lstlast.c \
		$(LST_PATH)/ft_lstadd_back.c \
		$(LST_PATH)/ft_lstclear.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		actions_bonus.c \
		utils.c \
		check_stack.c \
		checker.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	@gcc $(OBJS) -Llibft -lft -o $(NAME)
	@echo "=>push_swap program has been created"


%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

clean :
	@rm -f $(OBJS) $(B_OBJS)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C libft

re : fclean all

bonus : $(LIBFT) $(BONUS)

$(BONUS) : $(B_OBJS)
	@gcc $(B_OBJS) -Llibft -lft -o $(BONUS)
	@echo "=>checker program has been created"