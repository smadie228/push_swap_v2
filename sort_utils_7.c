/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:22 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 22:13:18 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_min_values(t_stack *a, t_stack *b, int *groups)
{
	int	*values;

	values = malloc(3 * sizeof(int));
	if (groups[1])
		values[0] = ft_get_list(a, ft_group_min(a->head))->value;
	if (groups[2])
		values[1] = ft_get_list(a, a->size
				- ft_get_group_size_bottom(a->head->prev)
				+ ft_group_min(ft_get_group_start(a->head->prev)))->value;
	if (groups[3])
		values[2] = b->head->prev->value;
	return (values);
}

void	ft_push_min(t_stack *a, t_stack *b, int *groups, int group_id)
{
	int	*values;
	int	next;

	while (groups[1] || groups[2] || groups[3])
	{
		values = ft_get_min_values(a, b, groups);
		next = ft_find_v(groups, values, 0);
		if (next == 1 && groups[1]--)
			ft_pushtop_savestate(a, b, ft_group_min(a->head), group_id);
		else if (next == 2 && groups[2]--)
		{
			ft_pushbot_savestate(a, b,
				ft_group_min(ft_get_group_start(a->head->prev)), group_id);
		}
		else if (groups[3]--)
		{
			if (b->size > 1)
				rrb(b);
			b->head->group = group_id;
		}
		free(values);
	}
}

void	ft_merge_not_sorted(t_stack *a, t_stack *b)
{
	int	*groups;
	int	group_id;

	if (a->head->trend == SORTED)
	{
		group_id = a->head->group;
		groups = ft_get_groups(a, b);
		ft_push_min(a, b, groups, group_id);
		free(groups);
	}
	else
	{
		group_id = a->head->group;
		groups = ft_get_groups(a, b);
		ft_push_max(a, b, groups, group_id);
		free(groups);
	}
}

void	ft_start_merge(t_stack *a, t_stack *b, int total_groups)
{
	int	i;
	int	group_id;
	int	group_size_t;
	int	group_size_b;

	i = 0;
	ft_set_trends(a, total_groups);
	while (i < total_groups / 4 || (i < total_groups / 2 && total_groups == 4))
	{
		group_id = a->head->group;
		group_size_t = ft_get_group_size_top(a->head);
		group_size_b = ft_get_group_size_bottom(a->head->prev);
		ft_first_merge(a, b, group_size_t, group_size_b);
		ft_set_group_index(b, group_id, group_size_t + group_size_b);
		i++;
	}
	while (i < total_groups / 2 && total_groups > 4)
	{
		ft_merge_not_sorted(a, b);
		i++;
	}
}

void	ft_main_loop(t_stack *a, t_stack *b,
					int total_groups, int current_stack)
{
	while (total_groups > 1)
	{
		if (current_stack == STACK_A
			&& (total_groups == 4 || total_groups == 2))
		{
			ft_in_place_merge(a, b, current_stack, total_groups);
			break ;
		}
		if (current_stack == STACK_B && total_groups == 2)
		{
			ft_simple_merge(b, a, current_stack);
			break ;
		}
		if (current_stack == STACK_A)
			ft_merge_loop(a, b, current_stack, total_groups);
		else
			ft_merge_loop(b, a, current_stack, total_groups);
		total_groups /= 4;
		current_stack = !current_stack;
	}
}
