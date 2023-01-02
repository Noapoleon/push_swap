/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 11:35:18 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	int	*tmp;
	t_stack	a;
	t_stack b;

	if (ac < 2)
		return (0);
	tmp = malloc(sizeof(int) * (ac - 1));
	if (tmp == NULL)
		return (ft_dprintf(2, "Erorr\n"), free(tmp), 0);
	if (parse_ints(&tmp, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), free(tmp), 0);
	// check if tmp already sorted before allocating whole stack (optional but would be better)
	if (init_stacks(&a, &b, tmp, ac - 1) == -1)
		return (ft_dprintf(2, "Error\n"), free(tmp), 0);
	//sort_stacks(&a, &b, tmp);
	//show_tmp(tmp, ac); // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
	show_stacks(&a, &b);
	free(tmp);
	//terminate_ps(&a, &b);
	return (0);
}
