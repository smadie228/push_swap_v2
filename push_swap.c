/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:41:34 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 03:47:01 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	**ft_argjoin(char **argv, int argc)
{
	int		i;
	char	*s;
	char	*temp;
	char	**result;

	i = 1;
	s = ft_strdup("");
	while (i < argc)
	{
		temp = ft_strjoin(s, argv[i]);
		free(s);
		s = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	result = ft_split(s, ' ');
	free(s);
	return (result);
}

void	ft_clear_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

void	*ft_clear(t_stack *a, char **arr)
{
	ft_clear_char(arr);
	ft_clear_stack(a);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		sorted;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (ft_any_digit(argv) == ERROR)
		ft_error();
	a = ft_arg_parser(ft_argjoin(argv, argc));
	if (!a)
		ft_error();
	sorted = ft_is_sorted(a);
	if (sorted == SORTED)
	{
		ft_clear_stack(a);
		return (0);
	}
	b = ft_stack_init();
	a->stack_name = STACK_A;
	b->stack_name = STACK_B;
	ft_stack_sort(a, b);
	ft_clear_stack(a);
	ft_clear_stack(b);
}
