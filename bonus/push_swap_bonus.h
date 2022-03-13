/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 02:11:04 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 03:58:21 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# define NOT_SORTED 0
# define SORTED 1
# define R_SORTED 2
# define ERROR -1
# define OK 1
# define IN_STACK 1
# define NOT_IN_STACK 0

typedef struct s_elem
{
	long int		value;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;
typedef struct s_stack
{
	t_elem	*head;
	int		size;
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
int		ft_minmax_int(char	*str);
int		ft_in_stack(t_stack *s, int value);
int		ft_is_sorted(t_stack *s);
void	ft_error(void);
void	*ft_clear(t_stack *a, char **arr);
int		ft_any_digit(char **s);
void	ft_clear_char(char **arr);
int		ft_use_operation_r(t_stack *a, t_stack *b, char *operation);
int		ft_use_operation_ps(t_stack *a, t_stack *b, char *operation);
#endif