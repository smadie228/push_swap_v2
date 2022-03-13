
NAME = push_swap

INCLUDES = push_swap.h

C = gcc

CFLAGS = -g -Wall -Wextra -Werror

SRCS =	push_swap.c merge_groups.c merge_utils.c\
		merge_utils_2.c merge_utils_3.c arg_parser.c\
		sort.c sort_utils.c sort_utils_2.c\
		sort_utils_3.c sort_utils_4.c sort_utils_5.c\
		sort_utils_6.c sort_utils_7.c stack_add_del.c\
		stack_manager.c stack_operation_push_swap.c\
		stack_operation_r_rotate.c stack_operation_rotate.c

OBJ = $(patsubst %.c,%.o,$(SRCS))

D_FILES = $(patsubst %.c,%.d,$(SRCS))

NAME_BONUS = checker

INCLUDES_BONUS = bonus/push_swap_bonus.h

SRCS_BONUS =	bonus/push_swap_bonus.c bonus/arg_parser_bonus.c bonus/stack_add_del_bonus.c\
				bonus/stack_operation_push_swap_bonus.c bonus/stack_operation_r_rotate_bonus.c\
				bonus/stack_operation_rotate_bonus.c bonus/stack_manager_bonus.c bonus/error_bonus.c\
				gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_BONUS = $(patsubst %.c,%.o,$(SRCS_BONUS))

D_FILES_BONUS = $(patsubst %.c,%.d,$(SRCS_BONUS))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	$(C) -o $(NAME) $(OBJ) $(CFLAGS) libft/libft.a

%.o : %.c
	$(C) $(CFLAGS) -O2 -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ) $(D_FILES)
	@rm -f $(OBJ_BONUS) $(D_FILES_BONUS)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C libft

re : fclean all

bonus : $(OBJ_BONUS)
	$(C) -o $(NAME_BONUS) $(OBJ_BONUS) $(CFLAGS) libft/libft.a

.PHONY : all clean fclean re bonus
