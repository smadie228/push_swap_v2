/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:36 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 14:47:05 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_trends_def(t_stack *a, int total_groups)
{
	int		i;
	t_elem	*ptr;

	i = 0;
	ptr = a->head;
	while (i < total_groups)
	{
		ft_put_group_trend(&ptr, R_SORTED);
		ft_put_group_trend(&ptr, SORTED);
		i += 2;
	}
}

void	ft_choose_trend(t_stack *a, int total_groups, int groups, int stack)
{
	while (total_groups > 4)
	{
		if (stack == STACK_A)
			stack = STACK_B;
		else
			stack = STACK_A;
		total_groups /= 4;
	}
	if (total_groups == 4)
	{
		if (stack == STACK_A)
			ft_set_trends_a4(a, groups);
		else
			ft_set_trends_b4(a, groups);
	}
	else
		ft_set_trends_def(a, groups);
}

void	ft_set_trends(t_stack *a, int total_groups)
{
	int	stack;
	int	groups;

	groups = total_groups;
	stack = STACK_A;
	if (total_groups == 4)
		ft_set_trends_def(a, groups);
	else
		ft_choose_trend(a, total_groups, groups, stack);
}

t_elem	*ft_get_group_start(t_elem *ptr)
{
	int		group;
	t_elem	*start;

	start = ptr;
	group = ptr->group;
	while (ptr->group == group)
	{	
		ptr = ptr->prev;
		if (ptr == start)
			break ;
	}
	ptr = ptr->next;
	return (ptr);
}

int	ft_group_max(t_elem *top)
{
	int		i;
	int		max;
	int		index;
	int		group;
	t_elem	*start;

	i = 0;
	start = top;
	group = top->group;
	max = top->value;
	while (top->group == group)
	{
		if (top->value > max)
		{
			max = top->value;
			index = i;
		}
		top = top->next;
		if (top == start)
			break ;
		i++;
	}
	return (index);
}
