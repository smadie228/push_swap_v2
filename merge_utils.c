/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:12 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 22:16:56 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_top(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	a->head->group = groups[0];
	if (a->head->trend == SORTED)
		a->head->trend = R_SORTED;
	else
		a->head->trend = SORTED;
	ft_operation_menager(a, b, P, stack_name);
	groups[1]--;
}

void	ft_push_bottom(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	if (a->size > 1)
		ft_operation_menager(a, b, RR, stack_name);
	a->head->group = groups[0];
	ft_operation_menager(a, b, P, stack_name);
	groups[2]--;
}

void	ft_r_bottom(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	if (b->size > 1)
		ft_operation_menager(a, b, RR, !stack_name);
	groups[3]--;
}

void	ft_rrr_bottom(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	if (a->size > 1 && b->size > 1)
		rrr(a, b);
	else if (a->size == 1 || b->size == 1)
		ft_operation_menager(a, b, RR, !stack_name);
	a->head->group = groups[0];
	ft_operation_menager(a, b, P, stack_name);
	groups[2]--;
	groups[3]--;
}

void	ft_r_top(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	if (b->size > 1)
		ft_operation_menager(b, a, R, stack_name);
	groups[3]--;
}
