/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_r_rotate_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:22 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:53:46 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		a->head = a->head->next;
	if (b->size > 0)
		b->head = b->head->next;
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		a->head = a->head->prev;
	if (b->size > 0)
		b->head = b->head->prev;
}
