/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:10:06 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 10:04:32 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if ((*tmp)[c++] == (*tmp)[i]) // consider dereferencing 'a' in a variable if program is slow
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
