/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:33 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 22:13:26 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_v(int x, int y, int flag)
{
	if (x > y && flag)
		return (1);
	if (x < y && !flag)
		return (1);
	return (0);
}

int	ft_check_2_v(int *groups, int *values, int flag)
{
	if (groups[1] && groups[2] && !groups[3])
	{
		if (ft_check_v(values[0], values[1], flag))
			return (1);
		else
			return (2);
	}
	if (groups[1] && !groups[2] && groups[3])
	{
		if (ft_check_v(values[0], values[2], flag))
			return (1);
		else
			return (3);
	}
	if (!groups[1] && groups[2] && groups[3])
	{
		if (ft_check_v(values[1], values[2], flag))
			return (2);
		else
			return (3);
	}
	return (0);
}

int	ft_check_3_v(int *values, int flag)
{
	if (ft_check_v(values[0], values[1], flag))
	{
		if (ft_check_v(values[0], values[2], flag))
			return (1);
		else
			return (3);
	}
	else if (ft_check_v(values[1], values[2], flag))
		return (2);
	else
		return (3);
}

int	ft_find_v(int *groups, int *values, int flag)
{
	if (groups[1] && !groups[2] && !groups[3])
		return (1);
	if (!groups[1] && groups[2] && !groups[3])
		return (2);
	if (!groups[1] && !groups[2] && groups[3])
		return (3);
	if (ft_check_2_v(groups, values, flag))
		return (ft_check_2_v(groups, values, flag));
	else
		return (ft_check_3_v(values, flag));
}

void	ft_push_max(t_stack *a, t_stack *b, int *groups, int group_id)
{
	int	*values;
	int	next;

	while (groups[1] || groups[2] || groups[3])
	{
		values = ft_get_max_values(a, b, groups);
		next = ft_find_v(groups, values, 1);
		if (next == 1 && groups[1]--)
			ft_pushtop_savestate(a, b, ft_group_max(a->head), group_id);
		else if (next == 2 && groups[2]--)
		{
			ft_pushbot_savestate(a, b,
				ft_group_max(ft_get_group_start(a->head->prev)), group_id);
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
