/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:10:06 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 09:49:26 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_ints(int	**a, int ac, char **av)
{
	int	i;
	int	c;

	i = 0;
	while (i < ac - 1)
	{
		if (parse_int(&(*a)[i], av[i + 1]) == -1)
			return (ft_dprintf(2, PSE_FORMAT,-1), -1);
		c = 0;
		while (c < i)
		{
			if ((*a)[c] == (*a)[i]) // consider dereferencing 'a' in a variable if program is slow
				return (ft_dprintf(2, PSE_DUPLICATE), -1);
			++c;
		}
		++i;
	}
	return (0);
}

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

int	check_repeat(int *a, int i)
{
	int	c;

	c = 0;
	while (c < i)
		if (a[c] == a[i])
			return (-1);
	return (0);
}
