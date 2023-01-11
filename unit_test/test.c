/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:18:36 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 18:40:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Goes through argv and counts the numbers of the stack as well as detects
// format errors and returns -1 if one is encountered (doesn't detect duplicate
// numbers as they are not parsed in this step)
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

// Sub-function of get_stack_format(), operates on a single string from argv
// Returns -1 when format error is encountered
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

// Parses a single integer and modifies the j pointer for next int in the same
// string
// Returning -1 here is probably useless as the format has been checked already
// but just in case I forgot something and need to debug later this will be
// useful
int	parse_int(int *n, char *nptr, int *j)
{
	int	i;

	if (ft_atois(n, nptr) == -1)
		return (-1);
	i = 0;
	while (nptr[i] == ' ')
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
		++i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		++i;
	while (nptr[i] == ' ')
		++i;
	*j += i;
	return (0);
}

// Parses all ints from argv and and returns error in case of duplicates
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
				return (-1);
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

int	stack_setup(t_stack *a, t_stack *b)
{


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
