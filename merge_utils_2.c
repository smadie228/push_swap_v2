/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:24 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 16:21:02 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_2(t_stack *a, t_stack *b, int *groups, int trend)
{
	if (groups[1] && groups[2] && !groups[3])
	{
		if (ft_check(a->head, a->head->prev, trend))
			return (1);
		else
			return (2);
	}
	if (groups[1] && !groups[2] && groups[3])
	{
		if (ft_check(a->head, b->head->prev, trend))
			return (1);
		else
			return (3);
	}
	if (!groups[1] && groups[2] && groups[3])
	{
		if (ft_check(a->head->prev, b->head->prev, trend))
			return (2);
		else
			return (3);
	}
	return (0);
}

int	ft_check_3(t_stack *a, t_stack *b, int trend)
{
	if (ft_check(a->head, a->head->prev, trend))
	{
		if (ft_check(a->head, b->head->prev, trend))
			return (1);
		else
			return (3);
	}
	else if (ft_check(a->head->prev, b->head->prev, trend))
		return (2);
	else
		return (3);
}

int	ft_find(t_stack *a, t_stack *b, int *groups, int trend)
{
	if (groups[1] && !groups[2] && !groups[3])
		return (1);
	if (!groups[1] && groups[2] && !groups[3])
		return (2);
	if (!groups[1] && !groups[2] && groups[3])
		return (3);
	if (ft_check_2(a, b, groups, trend))
		return (ft_check_2(a, b, groups, trend));
	else
		return (ft_check_3(a, b, trend));
}

int	ft_find_next(t_stack *a, t_stack *b, int *groups, int trend)
{
	groups[3]--;
	if (groups[2] && ((!groups[1] && !groups[3])
			|| (!groups[3] && groups[1]
				&& ft_check(a->head->prev, a->head, trend))
			|| (!groups[1] && groups[3]
				&& ft_check(a->head->prev, b->head->prev->prev, trend))
			|| (groups[1] && groups[3]
				&& ft_check(a->head->prev, a->head, trend)
				&& ft_check(a->head->prev,
					b->head->prev->prev, a->head->trend))))
	{
		groups[3]++;
		return (1);
	}
	groups[3]++;
	return (0);
}

void	ft_smart_rotate(t_stack *a, t_stack *b, int index)
{
	int	i;

	if (index <= a->size / 2 + a->size % 2)
	{
		i = 0;
		while (i < index)
		{
			ra(a);
			i++;
		}
		pb(a, b);
	}
	else
	{
		i = a->size;
		while (i > index)
		{
			rra(a);
			i--;
		}
		pb(a, b);
	}
}
