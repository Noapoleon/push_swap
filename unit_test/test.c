/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:18:36 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/10 02:46:34 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_format(int *n_elem, int ac, char **av)
{
	int	i;
	int	j;

	*n_elem = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			return (-1);
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				++j;
			if (av[i][j] == '+' || av[i][j] == '-')
				++j;
			if ((av[i][j] < '0' || av[i][j] > '9') || (!j && av[i][j] == '\0'))
				return (-1);
			while (av[i][j] >= '0' && av[i][j] <= '9')
				++j;
			if (av[i][j] != '\0' && av[i][j] != ' ')
				return (-1);
			++(*n_elem);
			while (av[i][j] && av[i][j] == ' ')
				++j;
		}
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	n_elem;

	if (ac < 2)
		return (ft_printf("Wrong arguments, fools!\n"), 0);
	if (get_stack_format(&n_elem, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	ft_printf("No error. :)\n");
	ft_printf("%d numbers found.\n", n_elem);
	return (0);
}
