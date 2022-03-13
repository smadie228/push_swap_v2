/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:19 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 21:49:29 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_merge_sort(t_stack *a, t_stack *b)
{
	int	total_groups;
	int	current_stack;

	current_stack = STACK_B;
	total_groups = ft_create_groups(a);
	ft_start_merge(a, b, total_groups);
	if (total_groups > 4)
		total_groups /= 4;
	else
		total_groups /= 2;
	ft_main_loop(a, b, total_groups, current_stack);
}

int	ft_min_index(t_stack *a)
{
	int		i;
	int		min;
	int		min_index;
	t_elem	*ptr;

	ptr = a->head;
	min = ptr->value;
	min_index = 0;
	i = 0;
	while (i < a->size)
	{
		if (ptr->value < min)
		{
			min = ptr->value;
			min_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (min_index);
}

int	ft_max_index(t_stack *a)
{
	int		i;
	int		max;
	int		max_index;
	t_elem	*ptr;

	ptr = a->head;
	max = ptr->value;
	max_index = 0;
	i = 0;
	while (i < a->size)
	{
		if (ptr->value > max)
		{
			max = ptr->value;
			max_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (max_index);
}

void	ft_small_sort(t_stack *a, t_stack *b)
{
	int	index;

	if (a->size > 3)
	{
		ft_smart_rotate(a, b, ft_min_index(a));
		ft_smart_rotate(a, b, ft_min_index(a));
	}
	index = ft_max_index(a);
	if (index == 0)
		ra(a);
	else if (index == 1)
		rra(a);
	if (a->head->value > a->head->next->value)
	{
		if (b->size > 1 && b->head->value < b->head->next->value)
			ss(a, b);
		else
			sa(a);
	}
	while (b->size > 0)
		pa(a, b);
}

void	ft_stack_sort(t_stack *a, t_stack *b)
{
	if (a->size > 5)
		ft_merge_sort(a, b);
	else
		ft_small_sort(a, b);
}
