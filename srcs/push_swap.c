/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/12 03:44:33 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	if (setup_stacks(&a, &b, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	sort_stacks(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->top->data > a->top->next->data)
		swap(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3)
		sort_big_stupid(a, b);
}
