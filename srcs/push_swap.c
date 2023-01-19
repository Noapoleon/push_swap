/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/19 08:26:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_push_swap ps;

	if (ac < 2)
		return (0);
	if (setup_push_swap(&ps, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	//if (setup_stacks(&a, &b, ac, av) == -1)
	//	return (ft_dprintf(2, "Error\n"), 0);
	ps.a.print = 1;
	ps.b.print = 1;
	sort_stacks(&ps);
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	free(ps.sorted);
	return (0);
}

void	sort_stacks(t_push_swap *ps)
{
	t_stack *a;
	t_stack *b;

	a = &ps->a;
	b = &ps->b;
	if (a->size == 2 && a->top->data > a->top->next->data)
		swap(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3)
	{
//		quicksort_b(ps, b, a, ps->size, 0);
		quicksort_a(ps, a, b, ps->size, 0);
//		test_sort_stupid(ps, a, b, ps->size, 0, ps->size - 1);
//		sort_big_less_stupid_still_stupid(a, b);
//		sort_big_stupid(a, b);
	}
}
