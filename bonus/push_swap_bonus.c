/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:56:25 by ndillon           #+#    #+#             */
/*   Updated: 2022/03/13 03:58:58 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_use_operation_ps(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 4))
		sa(a);
	else if (!ft_strncmp(operation, "sb\n", 4))
		sb(b);
	else if (!ft_strncmp(operation, "ss\n", 4))
		ss(a, b);
	else if (!ft_strncmp(operation, "pa\n", 4))
		pa(a, b);
	else if (!ft_strncmp(operation, "pb\n", 4))
		pb(a, b);
	else if (ft_use_operation_r(a, b, operation) == OK)
		return (OK);
	else
		return (ERROR);
	return (OK);
}

int	ft_use_operation_r(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "ra\n", 4))
		ra(a);
	else if (!ft_strncmp(operation, "rb\n", 4))
		rb(b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(operation, "rr\n", 4))
		rr(a, b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b);
	else
		return (ERROR);
	return (OK);
}

int	ft_read_operation(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_use_operation_ps(a, b, line) == ERROR)
		{
			ft_clear_stack(a);
			ft_clear_stack(b);
			return (ERROR);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (OK);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (ft_any_digit(argv) == ERROR)
		ft_error();
	a = ft_arg_parser(ft_argjoin(argv, argc));
	if (!a)
		ft_error();
	b = ft_stack_init();
	if (ft_read_operation(a, b) == ERROR)
		ft_error();
	if (ft_is_sorted(a) == SORTED)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_clear_stack(a);
	ft_clear_stack(b);
}
