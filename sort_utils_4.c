/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:47:38 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 14:47:39 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_group_min(t_elem *top)
{
	int		i;
	int		min;
	int		index;
	int		group;
	t_elem	*start;

	i = 0;
	start = top;
	group = top->group;
	min = top->value;
	while (top->group == group)
	{
		if (top->value < min)
		{
			min = top->value;
			index = i;
		}
		top = top->next;
		if (top == start)
			break ;
		i++;
	}
	return (index);
}

void	ft_push_from_top(t_stack *a, t_stack *b, int index, int group)
{
	int	i;

	i = 0;
	if (a->size == 1 || index == 0)
	{
		pb(a, b);
		b->head->group = group;
	}
	else
	{
		if (index == 1)
			sa(a);
		else
		{
			while (i++ < index)
				ra(a);
		}
		pb(a, b);
		b->head->group = group;
	}
}

void	ft_push_from_bottom(t_stack *a, t_stack *b, int index, int group)
{
	int	i;

	i = 0;
	(void)index;
	if (a->size == 1)
		pb(a, b);
	else
	{
		rra(a);
		pb(a, b);
		b->head->group = group;
	}
}

void	ft_pushtop_savestate(t_stack *a, t_stack *b, int index, int group)
{
	int	i;

	i = 0;
	if (a->size == 1 || index == 0)
		pb(a, b);
	else
	{
		while (i++ < index)
			ra(a);
		pb(a, b);
		while (index-- && a->size > 1)
			rra(a);
	}
	b->head->group = group;
	if (b->head->trend == SORTED)
		b->head->trend = R_SORTED;
	else
		b->head->trend = SORTED;
}

void	ft_pushbot_savestate(t_stack *a, t_stack *b, int index, int group)
{
	int	i;

	i = 0;
	if (a->size == 1)
		pb(a, b);
	else
	{
		index = ft_get_group_size_bottom(a->head->prev) - index - 1;
		if (a->size > 1)
			rra(a);
		while (i++ < index)
			rra(a);
		pb(a, b);
		while (index-- > 0 && a->size > 1)
			ra(a);
	}
	b->head->group = group;
}
