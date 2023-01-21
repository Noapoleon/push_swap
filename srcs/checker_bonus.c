/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 21:29:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_push_swap	ps;
	t_ops		*ops;

	if (ac < 2) // should i do that?
		return (0);
	if (setup_push_swap(&ps, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	if (get_operations(&ops, &ps.a, &ps.b) == -1)
		return (clear_stack(&ps.a), ft_dprintf(2, "Error\n"), 0);
	do_ops(ops);
	if (is_sorted(&ps.a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	free(ps.sorted);
	clear_ops(ops);
	return (0);
}
