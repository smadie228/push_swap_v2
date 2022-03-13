/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:42:32 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 00:39:00 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_operation_menager(t_stack *a, t_stack *b, int operation, int stack)
{
	t_stack	*s;

	if (a->stack_name == STACK_B)
	{
		s = a;
		a = b;
		b = s;
	}
	ft_operation_use(a, b, operation, stack);
}

void	ft_operation_use(t_stack *a, t_stack *b, int operation, int stack)
{
	if (stack == STACK_A)
	{
		if (operation == S)
			sa(a);
		else if (operation == P)
			pb(a, b);
		else if (operation == R)
			ra(a);
		else if (operation == RR)
			rra(a);
		return ;
	}
	if (operation == S)
		sb(b);
	else if (operation == P)
		pa(a, b);
	else if (operation == R)
		rb(b);
	else if (operation == RR)
		rrb(b);
}
