/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 06:35:16 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_push_swap	ps;

	if (ac < 2)
		return (0);
	ps.a = &a;
	ps.b = &b;
	if (setup_push_swap(&ps, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"), 0);
	a.print = 1;
	b.print = 1;
	sort_stacks(&ps);
	clear_stack(&a);
	clear_stack(&b);
	free(ps.sorted);
	return (0);
}

void	sort_stacks(t_push_swap *ps)
{
	if (is_sorted_stack(ps->a))
		return ;
	if (ps->a->size == 2 && ps->a->top->data > ps->a->top->next->data)
		swap(ps->a);
	else if (ps->a->size == 3)
		sort_three(ps->a);
	else if (ps->a->size == 4 || ps->a->size == 5)
		sort_four_five(ps);
	else if (ps->a->size > 5 && ps->a->size < 1500)
		fraction_sort(ps);
	else if (ps->a->size >= 1500)
		quicksort_a(ps, ps->size, 0);
}
