/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:32 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 22:05:34 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_group_size_top(t_elem *ptr)
{
	int		group;
	int		size;
	t_elem	*start;

	start = ptr;
	size = 0;
	group = ptr->group;
	while (ptr->group == group)
	{
		size++;
		ptr = ptr->next;
		if (ptr == start)
			break ;
	}
	return (size);
}

int	ft_get_group_size_bottom(t_elem *ptr)
{
	int		group;
	int		size;
	t_elem	*start;

	start = ptr;
	size = 0;
	group = ptr->group;
	while (ptr->group == group)
	{
		size++;
		ptr = ptr->prev;
		if (ptr == start)
			break ;
	}
	return (size);
}

int	ft_check(t_elem *ptr_t, t_elem *ptr_b, int trend)
{
	if ((ptr_t->value < ptr_b->value && trend == SORTED)
		|| (ptr_t->value > ptr_b->value && trend == R_SORTED))
		return (1);
	return (0);
}

void	ft_in_place_merge_4(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	int	trend;
	int	next;

	trend = a->head->trend;
	while (groups[1] || groups[2] || groups[3])
	{
		next = ft_find(a, b, groups, trend);
		if (next == 1)
			ft_push_top(a, b, stack_name, groups);
		else if (next == 2)
			ft_push_bottom(a, b, stack_name, groups);
		else
		{
			ft_operation_menager(a, b, RR, !stack_name);
			groups[3]--;
		}
	}
	free(groups);
}

void	ft_in_place_merge_2(t_stack *a, t_stack *b, int stack_name)
{
	int	group;
	int	i;

	group = a->head->group;
	ft_push_group(a, b, stack_name);
	i = a->size;
	while (b->size > 0)
	{
		if (b->head->value < a->head->value || i == 0)
			ft_operation_menager(a, b, P, !stack_name);
		else
			i--;
		ft_operation_menager(a, b, R, stack_name);
	}
	while (ft_is_sorted(a) != SORTED)
		ft_operation_menager(a, b, R, stack_name);
}
