/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:32 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:55:03 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (stack);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

t_elem	*ft_new_elem(int value, t_elem *last)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (new_elem)
	{
		new_elem->value = value;
		new_elem->next = last;
	}
	return (new_elem);
}

void	*ft_clear_stack(t_stack *s)
{
	int		i;
	t_elem	*temp;

	i = 0;
	temp = s->head;
	while (i < s->size)
	{
		s->head = s->head->next;
		free(temp);
		temp = s->head;
		i++;
	}
	free(s);
	return (NULL);
}
