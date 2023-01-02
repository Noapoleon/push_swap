/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 09:10:27 by nlegrand         ###   ########.fr       */
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
