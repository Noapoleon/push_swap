/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:18:36 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/10 18:45:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "push_swap.h"
int	get_string_format(int *n_elem, char *str);

int	get_stack_format(int *n_elem, int ac, char **av)
{
	int	i;

	*n_elem = 0;
	i = 1;
	while (i < ac)
		if (get_string_format(n_elem, av[i++]) == -1)
			return (-1);
	return (0);
}

int	get_string_format(int *n_elem, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			++i;
		if (str[i] == '+' || str[i] == '-')
			++i;
		if ((str[i] < '0' || str[i] > '9') || (!i && str[i] == '\0'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
		if (str[i] != '\0' && str[i] != ' ')
			return (-1);
		++(*n_elem);
		while (str[i] && str[i] == ' ')
			++i;
	}
	return (0);
}

int	parse_int(int *n, char *nptr, int *j)
{
	int	i;

	if (ft_atois(n, nptr) == -1)
		return (-1);
	i = 0;
	while (nptr[i])
	{
		while (nptr[i] == ' ')
			++i;
		if (nptr[i] == '+' || nptr[i] == '-')
			++i;
		while (nptr[i] >= '0' && nptr[i] <= '9')
			++i;
		while (nptr[i] == ' ')
			++i;
	}
	*j += i;
	return (0);
}

// Parses all ints from argv and and returns error in case of bad formatting
int	parse_ints(int	*tmp, int ac, char **av)
{
	int	i;
	int	j;
	int	c;
	int	dc;

	i = 1;
	c = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (parse_int(&tmp[c], av[i] + j, &j) == -1)
				return (ft_printf("why???\n"), -1);
			dc = 0;
			while (dc < c)
				if (tmp[dc++] == tmp[c])
					return (-1);
			++c;
		}
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	n_elem;
	int	*tmp;

	if (ac < 2)
		return (ft_printf("Wrong arguments, fools!\n"), 0);
	if (get_stack_format(&n_elem, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	tmp = malloc(sizeof(int) * n_elem);
	if (tmp == NULL)
		return (ft_dprintf(2, "Error\n"), 0);
	if (parse_ints(tmp, ac, av) == -1) // give n_elem??
		return (ft_dprintf(2, "Error\n"), free(tmp), 0);
	int i = 0;
	while (i < n_elem)
		ft_printf("%d\n", tmp[i++]);
	ft_printf("No error. :)\n");
	ft_printf("%d numbers found.\n", n_elem);
	return (0);
}
