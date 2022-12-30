/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2022/12/30 23:48:10 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	int	*a;
	int	*b;

	a = malloc(sizeof(int) * (ac - 1));
	b = malloc(sizeof(int) * (ac - 1));
	if (a == NULL || b == NULL)
		return (ft_dprintf(2, PSE_MALLOC_STACKS), free(a), free(b), 0);
	if (parse_ints(&a, ac, av) == -1)
		return (ft_dprintf(2, PSE_PARSE), free(a), free(b), 0);
	show_parsed_list(a, ac);
	free(a);
	free(b);
	return (0);
}

int	parse_ints(int	**a, int ac, char **av)
{
	int	i;

	*a = malloc(sizeof(int) * (ac - 1));
	if (*a == NULL)
		return (-1);
	i = 1;
	while (i < ac)
	{
		(*a)[i - 1] = ft_atoi(av[i]); // make custom atoi later to detect overflow
		++i;
	}
	return (0);
}
