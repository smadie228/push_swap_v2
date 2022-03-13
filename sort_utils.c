/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:45 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 14:24:46 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_group_trend(t_elem **ptr, int trend)
{
	int	group;

	if (*ptr == (*ptr)->next)
	{
		(*ptr)->trend = trend;
		return ;
	}
	group = (*ptr)->group;
	while ((*ptr)->group == group)
	{
		(*ptr)->trend = trend;
		*ptr = (*ptr)->next;
	}
}

void	ft_put_group_trend_save(t_elem *ptr, int trend)
{
	int	group;

	if (ptr == ptr->next)
	{
		ptr->trend = trend;
		return ;
	}
	group = ptr->group;
	while (ptr->group == group)
	{
		ptr->trend = trend;
		ptr = ptr->next;
	}
}

void	ft_set_group_index(t_stack *a, int index, int count)
{
	int		i;
	t_elem	*ptr;

	i = 0;
	ptr = a->head;
	while (i < count)
	{
		ptr->group = index;
		ptr = ptr->next;
		i++;
	}
}

void	ft_put_group_index(t_stack *a, int groups_of_two, int groups_of_one)
{
	int		i;
	t_elem	*ptr;

	i = 0;
	ptr = a->head;
	while (groups_of_two--)
	{
		ptr->group = i;
		ptr = ptr->next;
		ptr->group = i;
		ptr = ptr->next;
		i++;
	}
	while (groups_of_one--)
	{
		ptr->group = i;
		ptr = ptr->next;
		i++;
	}
}

int	ft_create_groups(t_stack *a)
{
	int	total_groups;
	int	groups_of_two;
	int	groups_of_one;

	groups_of_one = 0;
	if (a->size % 2 != 0)
		groups_of_one++;
	groups_of_two = a->size / 2;
	total_groups = 2;
	while (total_groups < a->size)
		total_groups *= 2;
	total_groups /= 2;
	if (total_groups * 2 == a->size)
	{
		ft_put_group_index(a, groups_of_two, groups_of_one);
		return (total_groups);
	}
	while (groups_of_two + groups_of_one != total_groups)
	{
		groups_of_two -= 1;
		groups_of_one += 2;
	}
	ft_put_group_index(a, groups_of_two, groups_of_one);
	return (total_groups);
}
