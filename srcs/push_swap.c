/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:55:18 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/10 02:02:25 by nlegrand         ###   ########.fr       */
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
	init_stack(a, 'a');
	init_stack(b, 'b');
	if (parse_stack(&a, ac, av) == -1)
		return (ft_dprintf(2, "Error\n"));
	//if (parse_ints(&tmp, ac, av) == -1)
	//	return (ft_dprintf(2, "Error\n"), free(tmp), 0);
	//if (init_stacks(&a, &b, tmp, ac - 1) == -1) // move into parse_ints()
	//	return (ft_dprintf(2, "Error\n"), free(tmp), 0);
	//show_stacks(&a, &b); // remove later
	sort_stacks(&a, &b);
	//show_stacks(&a, &b); // remove later
	//instruction_tests(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	free(tmp);
	return (0);
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;

	if (a->size == 2 && a->top->data > a->top->next->data)
		swap(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3)
		sort_big_stupid(a, b);

	//if (is_sorted(a))
	//	ft_printf("Stack is sorted!\n");
	//else
	//	ft_printf("Stack is NOT sorted...\n");
	//show_stacks_status(a, b);
}
