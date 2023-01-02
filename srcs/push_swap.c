/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 08:23:38 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	int	*a;
	int	*b;

	if (ac < 2)
		return (0);
	a = malloc(sizeof(int) * (ac - 1));
	b = malloc(sizeof(int) * (ac - 1));
	if (a == NULL || b == NULL)
		return (ft_dprintf(2, PSE_MALLOC_STACKS), free(a), free(b), 0);
	if (parse_ints(&a, ac, av) == -1)
		return (ft_dprintf(2, PSE_PARSE), free(a), free(b), 0);
	show_stacks(a, b, ac); // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
	free(a);
	free(b);
	return (0);
}

int	parse_ints(int	**a, int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (parse_int(&(*a)[i], av[i + 1]) == -1)
			return (-1);
//		if ( 
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
