/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:10:06 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/10 02:16:35 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_format(int *n_elem, int ac, char **av)
{
	int	i;
	int	j;
	//char	*nptr;

	*n_elem = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[j] && av[j] == ' ')
			++j;
		if (av[j] == '+' || av[j] == '-')
			++j;
		while (av[j] >= '0' && av[j] <= '9')
			++j;
		if (av
	}
	ft_printf("how many numbers? -> %d\n", n_elem);
}

int	parse_stack(t_stack *a, int ac, char **av)
{
	int	*tmp;
	int	n_elem;

	if (get_stack_format(&n_elem, ac, av) == -1)
		return (-1);
	ft_printf("passed the format test lmao!\n"); // remove later
	return (0);
}

// Parses all ints from argv and and returns error in case of bad formatting
int	parse_ints(int	**tmp, int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	while (i < ac - 1)
	{
		if (parse_int(&(*tmp)[i], av[i + 1]) == -1)
			return (-1);
		c = 0;
		while (c < i)
			if ((*tmp)[c++] == (*tmp)[i])
				return (-1);
		++i;
	}
	return (0);
}

// Modified version of atoi that parses one int from argv and returns an error
// if a formatting error is met
int	parse_int(int *n, char *nptr)
{
	long	nb;
	int		sign;

	nb = 0;
	while (*nptr && (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == ' ')))
		++nptr;
	sign = 1;
	if ((*nptr == '-') || (*nptr == '+'))
		if (*nptr++ == '-')
			sign = -1;
	if (*nptr < '0' || *nptr > '9')
		return (-1);
	while ((*nptr >= '0') && (*nptr <= '9'))
	{
		nb = (nb * 10) + (*nptr++ - 48);
		if (nb > (long)INT_MAX + (sign == -1))
			return (-1);
	}
	return ((*n = sign * (int)nb), 0);
}
