/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:47:48 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 21:55:39 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_group(t_stack *a, t_stack *b, int stack)
{
	int	group;

	group = a->head->group;
	while (a->head->group == group)
	{
		ft_operation_menager(a, b, P, stack);
		if (b->head->trend == SORTED)
			b->head->trend = R_SORTED;
		else
			b->head->trend = SORTED;
	}
}

int	*ft_get_groups(t_stack *a, t_stack *b)
{
	int	*groups;

	groups = malloc(4 * sizeof(int));
	groups[0] = b->head->prev->group;
	groups[1] = ft_get_group_size_top(a->head);
	groups[2] = ft_get_group_size_bottom(a->head->prev);
	groups[3] = ft_get_group_size_bottom(b->head->prev);
	return (groups);
}

void	ft_merge_loop(t_stack *a, t_stack *b,
					int current_stack, int total_groups)
{
	int	i;

	i = 0;
	while (i < total_groups / 4)
	{
		ft_simple_merge(a, b, current_stack);
		i++;
	}
	while (i < total_groups / 2)
	{
		ft_merge_4(a, b, current_stack, ft_get_groups(a, b));
		i++;
	}
}

void	ft_set_trends_a4(t_stack *a, int total_groups)
{
	int		i;
	t_elem	*ptr;

	i = 0;
	ptr = a->head;
	while (i < total_groups)
	{
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		i += 16;
	}
}

void	ft_set_trends_b4(t_stack *a, int total_groups)
{
	int		i;
	t_elem	*ptr;

	i = 0;
	ptr = a->head;
	while (i < total_groups)
	{
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		ft_put_group_trend(&ptr, SORTED);
		i += 4;
	}
}
