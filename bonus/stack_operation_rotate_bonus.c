/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_rotate_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:44:22 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:53:48 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack	*a)
{
	if (a->size > 0)
		a->head = a->head->next;
}

void	rb(t_stack *b)
{
	if (b->size > 0)
		b->head = b->head->next;
}

void	rra(t_stack *a)
{
	if (a->size > 0)
		a->head = a->head->prev;
}

void	rrb(t_stack *b)
{
	if (b->size > 0)
		b->head = b->head->prev;
}
