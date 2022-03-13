/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:15 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 22:16:44 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_2(t_stack *a, t_stack *b, int stack_name, int *groups)
{
	while (groups[0] || groups[1])
	{
		if (groups[0]
			&& (!groups[1] || ft_check(a->head, a->head->prev, groups[3])))
		{
			groups[0]--;
			ft_operation_menager(a, b, P, stack_name);
			if (b->head->trend == SORTED)
				b->head->trend = R_SORTED;
			else
				b->head->trend = SORTED;
		}
		else
		{
			groups[1]--;
			if (a->size > 1)
				ft_operation_menager(a, b, RR, stack_name);
			a->head->group = groups[2];
			ft_operation_menager(a, b, P, stack_name);
		}
	}
}

void	ft_simple_merge(t_stack *a, t_stack *b, int stack_name)
{
	int	groups[4];

	groups[0] = ft_get_group_size_top(a->head);
	groups[1] = ft_get_group_size_bottom(a->head->prev);
	groups[2] = a->head->group;
	groups[3] = a->head->trend;
	ft_merge_2(a, b, stack_name, groups);
}

void	ft_merge_4(t_stack *a, t_stack *b, int stack_name, int *groups)
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
			if (ft_find_next(a, b, groups, trend) && groups[2])
				ft_rrr_bottom(a, b, stack_name, groups);
			else
				ft_r_bottom(a, b, stack_name, groups);
		}
	}
	free(groups);
}

void	ft_in_place_merge(t_stack *a, t_stack *b, int stack_name, int count)
{
	int	*groups;

	if (count == 2)
		ft_in_place_merge_2(a, b, stack_name);
	else if (count == 4)
	{
		ft_push_group(a, b, stack_name);
		ft_simple_merge(a, b, stack_name);
		groups = ft_get_groups(b, a);
		ft_in_place_merge_4(b, a, !stack_name, groups);
	}
}
