/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:44:22 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/12 20:50:10 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack	*a)
{
	if (a->size > 0)
		a->head = a->head->next;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	if (b->size > 0)
		b->head = b->head->next;
	ft_putendl_fd("rb", 1);
}

void	rra(t_stack *a)
{
	if (a->size > 0)
		a->head = a->head->prev;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	if (b->size > 0)
		b->head = b->head->prev;
	ft_putendl_fd("rrb", 1);
}
