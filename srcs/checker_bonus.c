/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/12 16:51:31 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_ops		*ops;

	if (ac < 2) // should i do that?
		return (0);
	if (setup_stacks(&a, &b, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	if (get_operations(&ops, &a, &b) == -1)
		return (clear_stack(&a), ft_dprintf(2, "Error\n"), 0);
	do_ops(ops);
	if (is_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&a);
	clear_stack(&b);
	clear_ops(ops);
	return (0);
}