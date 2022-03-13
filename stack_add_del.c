/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:14 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 14:42:15 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_stack(t_stack *s, t_elem *ptr, t_elem *elem)
{
	s->size++;
	if (s->head == NULL)
	{
		s->head = elem;
		elem->next = elem;
		elem->prev = elem;
		return ;
	}
	if (!ptr)
		ptr = s->head->prev;
	elem->next = ptr->next;
	elem->prev = ptr;
	ptr->next = elem;
	elem->next->prev = elem;
}

t_elem	*ft_del_from_stack(t_stack *s, t_elem *elem)
{
	t_elem	*ptr;

	ptr = elem;
	if (s->size == 0)
		return (NULL);
	if (s->size == 1)
		s->head = NULL;
	else
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}
	s->size--;
	return (ptr);
}
