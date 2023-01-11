/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:01 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 22:15:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	t_ops	ops;

	if (ac < 2) // should i do that?
		return (0);
	if (setup_stacks(&a, &b, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	if (get_operations(&ops) == -1)
		return (clear_stack(a), ft_dprintf(2, "Error\n"), 0);
	if (is_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

int	is_sorted(t_stack *s)
{
	t_stack_list *curr;

	if (s->top == NULL || s->size == 0)
		return (0);
	curr = s->top;
	while (curr != s->top->prev)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
