/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push_swap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:26 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 20:52:16 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *s)
{
	t_elem	*ptr;

	if (s->size > 1)
	{
		ptr = ft_del_from_stack(s, s->head->next);
		ft_add_to_stack(s, s->head->prev, ptr);
		s->head = s->head->prev;
	}
	ft_putendl_fd("sa", 1);
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
	ft_putendl_fd("sb", 1);
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
	ft_putendl_fd("ss", 1);
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
	ft_putendl_fd("pa", 1);
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
	ft_putendl_fd("pb", 1);
}
