/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:48:33 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:36:38 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# define NOT_SORTED 0
# define SORTED 1
# define R_SORTED 2
# define ERROR -1
# define OK 1
# define STACK_A 0
# define STACK_B 1
# define IN_STACK 1
# define NOT_IN_STACK 0
# define MERGE_2 0
# define MERGE_4 1
# define S 0
# define P 1
# define R 2
# define RR 3
# define O_RA 0
# define O_RB 1
# define O_RRA 2
# define O_RRB 3
# define O_SA 4
# define O_SB 5
# define GET 0
# define SET 1
# define DEL 2

typedef struct s_elem
{
	long int		value;
	int				group;
	int				trend;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;
typedef struct s_stack
{
	t_elem	*head;
	int		size;
	int		stack_name;
}	t_stack;

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack	*a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	**ft_argjoin(char **argv, int argc);
t_stack	*ft_arg_parser(char **argv);
t_stack	*ft_stack_init(void);
void	*ft_clear_stack(t_stack *s);
t_elem	*ft_new_elem(int value, t_elem *last);
void	ft_add_to_stack(t_stack *s, t_elem *ptr, t_elem *elem);
t_elem	*ft_del_from_stack(t_stack *s, t_elem *elem);
int		ft_find_next(t_stack *a, t_stack *b, int *groups, int trend);
int		ft_find(t_stack *a, t_stack *b, int *groups, int trend);
int		ft_check_2(t_stack *a, t_stack *b, int *groups, int trend);
int		ft_check_3(t_stack *a, t_stack *b, int trend);
int		ft_minmax_int(char	*str);
int		ft_in_stack(t_stack *s, int value);
int		ft_is_sorted(t_stack *s);
int		ft_is_trend(t_stack *s);
int		ft_create_groups(t_stack *a);
void	ft_set_group_index(t_stack *a, int index, int count);
void	ft_push_group(t_stack *a, t_stack *b, int stack);
void	ft_put_group_index(t_stack *a, int groups_of_two, int groups_of_one);
void	ft_put_group_trend(t_elem **ptr, int trend);
void	ft_put_group_trend_save(t_elem *ptr, int trend);
void	ft_operation_menager(t_stack *a, t_stack *b, int operation, int stack);
void	ft_r_top(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_r_bottom(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_rrr_bottom(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_push_top(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_push_bottom(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_push_from_top(t_stack *a, t_stack *b, int index, int group);
void	ft_push_from_bottom(t_stack *a, t_stack *b, int index, int group);
void	ft_pushtop_savestate(t_stack *a, t_stack *b, int index, int group);
void	ft_pushbot_savestate(t_stack *a, t_stack *b, int index, int group);
int		*ft_get_groups(t_stack *a, t_stack *b);
int		ft_get_group_size_bottom(t_elem *ptr);
int		ft_get_group_size_top(t_elem *ptr);
void	ft_set_trends_def(t_stack *a, int total_groups);
void	ft_choose_trend(t_stack *a, int total_groups, int groups, int stack);
void	ft_set_trends(t_stack *a, int total_groups);
int		ft_group_max(t_elem *top);
int		ft_group_min(t_elem *top);
t_elem	*ft_get_group_start(t_elem *ptr);
int		ft_check(t_elem *ptr_t, t_elem *ptr_b, int trend);
t_elem	*ft_get_list(t_stack *s, int index);
void	ft_operation_menager(t_stack *a, t_stack *b, int operation, int stack);
void	ft_operation_use(t_stack *a, t_stack *b, int operation, int stack);
int		ft_check_v(int x, int y, int flag);
void	ft_smart_rotate(t_stack *a, t_stack *b, int index);
int		ft_max_index(t_stack *a);
int		ft_min_index(t_stack *a);
int		ft_check_2_v(int *groups, int *values, int flag);
int		ft_check_3_v(int *values, int flag);
int		ft_find_v(int *groups, int *values, int flag);
void	ft_stack_sort(t_stack *a, t_stack *b);
void	ft_small_sort(t_stack *a, t_stack *b);
void	ft_start_merge(t_stack *a, t_stack *b, int total_groups);
void	ft_merge_sort(t_stack *a, t_stack *b);
void	ft_swap_sort(t_stack *a, t_stack *b,
			int group_size_t, int group_size_b);
void	ft_merge_not_sorted(t_stack *a, t_stack *b);
void	ft_first_merge(t_stack *a, t_stack *b, int group_size_t,
			int group_size_b);
void	ft_main_loop(t_stack *a, t_stack *b,
			int total_groups, int current_stack);
void	ft_merge_loop(t_stack *a, t_stack *b,
			int current_stack, int total_groups);
void	ft_set_trends_a4(t_stack *a, int total_groups);
void	ft_set_trends_b4(t_stack *a, int total_groups);
void	ft_simple_merge(t_stack *a, t_stack *b, int stack_name);
void	ft_merge_2(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_merge_4(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_in_place_merge(t_stack *a, t_stack *b, int stack_name, int count);
void	ft_in_place_merge_2(t_stack *a, t_stack *b, int stack_name);
void	ft_in_place_merge_4(t_stack *a, t_stack *b,
			int stack_name, int *groups);
int		*ft_get_min_values(t_stack *a, t_stack *b, int *groups);
int		*ft_get_max_values(t_stack *a, t_stack *b, int *groups);
void	ft_merge_b4(t_stack *a, t_stack *b, int stack_name, int *groups);
void	ft_push_min(t_stack *a, t_stack *b, int *groups, int group_id);
void	ft_push_max(t_stack *a, t_stack *b, int *groups, int group_id);
void	ft_error(void);
void	*ft_clear(t_stack *a, char **arr);
int		ft_any_digit(char **s);
void	ft_clear_char(char **arr);

#endif