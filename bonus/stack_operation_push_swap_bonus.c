/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push_swap_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:26 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:53:43 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *s)
{
	t_elem	*ptr;

	if (s->size > 1)
	{
		ptr = ft_del_from_stack(s, s->head->next);
		ft_add_to_stack(s, s->head->prev, ptr);
		s->head = s->head->prev;
	}
}

void	sb(t_stack *s)
{
	t_elem	*ptr;

	if (s->size > 1)
	{
		ptr = ft_del_from_stack(s, s->head->next);
		ft_add_to_stack(s, s->head->prev, ptr);
		s->head = s->head->prev;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	t_elem	*ptr;

	if (a->size > 1)
	{
		ptr = ft_del_from_stack(a, a->head->next);
		ft_add_to_stack(a, a->head->prev, ptr);
		a->head = a->head->prev;
	}
	if (b->size > 1)
	{
		ptr = ft_del_from_stack(b, b->head->next);
		ft_add_to_stack(b, b->head->prev, ptr);
		b->head = b->head->prev;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	t_elem	*ptr;

	if (b->size > 0)
	{
		b->head = b->head->next;
		ptr = ft_del_from_stack(b, b->head->prev);
		if (a->size == 0)
			ft_add_to_stack(a, a->head, ptr);
		else
			ft_add_to_stack(a, a->head->prev, ptr);
		a->head = a->head->prev;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_elem	*ptr;

	if (a->size > 0)
	{
		a->head = a->head->next;
		ptr = ft_del_from_stack(a, a->head->prev);
		if (b->size == 0)
			ft_add_to_stack(b, b->head, ptr);
		else
			ft_add_to_stack(b, b->head->prev, ptr);
		b->head = b->head->prev;
	}
}
