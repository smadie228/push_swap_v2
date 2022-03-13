/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:34 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 19:16:03 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_trend(t_stack *s)
{
	if ((s->head->value > s->head->next->value
			&& s->head->trend == SORTED)
		|| (s->head->value < s->head->next->value
			&& s->head->trend == R_SORTED))
		return (1);
	return (0);
}

void	ft_swap_sort(t_stack *a, t_stack *b, int group_size_t, int group_size_b)
{
	if (group_size_t > 1 && group_size_b > 1)
	{
		if (!ft_is_trend(a) || ft_is_trend(b))
			ss(a, b);
		if (!ft_is_trend(a))
			sa(a);
	}
	if (ft_is_trend(b))
		sb(b);
	if (group_size_b > 1)
	{
		pb(a, b);
		if (ft_is_trend(b))
			sb(b);
	}
	if (group_size_b > 1 || group_size_t > 1)
		pb(a, b);
	if (ft_is_trend(b))
		sb(b);
}

void	ft_first_merge(t_stack *a, t_stack *b, int group_size_t,
	int group_size_b)
{
	int	index_top;
	int	index_bottom;
	int	group;

	group = a->head->group;
	if (a->head->trend == SORTED)
	{
		index_top = ft_group_min(a->head);
		index_bottom = ft_group_min(ft_get_group_start(a->head->prev));
		ft_put_group_trend_save(a->head, R_SORTED);
	}
	else
	{
		index_top = ft_group_max(a->head);
		index_bottom = ft_group_max(ft_get_group_start(a->head->prev));
		ft_put_group_trend_save(a->head, SORTED);
	}
	ft_push_from_top(a, b, index_top, group);
	if (index_bottom == 0 && group_size_b > 1)
		rra(a);
	ft_push_from_bottom(a, b, index_bottom, group);
	if (group_size_b > 1 && index_bottom == 1)
		rra(a);
	ft_swap_sort(a, b, group_size_t, group_size_b);
}

t_elem	*ft_get_list(t_stack *s, int index)
{
	int		i;
	t_elem	*list;

	i = 0;
	list = s->head;
	while (i < index)
	{
		list = list->next;
		i++;
	}
	return (list);
}

int	*ft_get_max_values(t_stack *a, t_stack *b, int *groups)
{
	int	*values;

	values = malloc(3 * sizeof(int));
	if (groups[1])
		values[0] = ft_get_list(a, ft_group_max(a->head))->value;
	if (groups[2])
		values[1] = ft_get_list(a, a->size
				- ft_get_group_size_bottom(a->head->prev)
				+ ft_group_max(ft_get_group_start(a->head->prev)))->value;
	if (groups[3])
		values[2] = b->head->prev->value;
	return (values);
}
