/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:09 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 02:53:37 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_in_stack(t_stack *s, int value)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = s->head;
	while (i < s->size)
	{
		if (elem->value == value)
			return (IN_STACK);
		elem = elem->next;
		i++;
	}
	return (NOT_IN_STACK);
}

int	ft_minmax_int(char	*str)
{
	int			sign;
	long int	nmb;

	nmb = 0;
	sign = 0;
	while (*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	if (*str == '-')
	{
		sign = 1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		nmb += *str - 48;
		if ((nmb > INT_MAX && !sign) || (-nmb < INT_MIN && sign))
			return (ERROR);
		nmb *= 10;
		++str;
	}
	return (OK);
}

int	ft_is_sorted(t_stack *s)
{
	t_elem	*ptr;
	int		trend;

	if (s->size < 2)
		return (SORTED);
	ptr = s->head->next;
	trend = NOT_SORTED;
	while (ptr != s->head)
	{
		if (ptr->prev->value < ptr->value && trend != R_SORTED)
			trend = SORTED;
		else if (ptr->prev->value > ptr->value && trend != SORTED)
			trend = R_SORTED;
		else
			return (NOT_SORTED);
		ptr = ptr->next;
	}
	return (trend);
}

t_stack	*ft_arg_parser(char **argv)
{
	int		i;
	int		index;
	t_stack	*a;

	a = ft_stack_init();
	index = 0;
	while (argv[index])
	{
		i = 0;
		while (argv[index][i])
		{
			if (!ft_isdigit(argv[index][i])
				&& ((argv[index][i] != '-' || argv[index][i] != '+') && i > 0))
				return (ft_clear(a, argv));
			i++;
		}
		if (ft_minmax_int(argv[index]) == ERROR
			|| ft_in_stack(a, ft_atoi(argv[index])))
			return (ft_clear(a, argv));
		ft_add_to_stack(a, NULL, ft_new_elem(ft_atoi(argv[index]), NULL));
		index++;
	}
	ft_clear_char(argv);
	return (a);
}

int	ft_any_digit(char **s)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (s[i])
	{
		flag = 0;
		j = 0;
		while (s[i][j])
		{
			if (ft_isdigit(s[i][j]))
				flag = 1;
			j++;
		}
		if (!flag)
			return (ERROR);
		i++;
	}
	return (OK);
}
