/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:18:36 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 21:57:27 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending_portion(t_stack_list *s, int size)
{
	t_stack_list *curr;

	curr = s;
	while (--size)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_descending_portion(t_stack_list *s, int size)
{
	t_stack_list *curr;

	curr = s;
	while (--size)
	{
		if (curr->data < curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

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
	if (is_descending_portion(ps.a.top, ps.size))
		ft_printf("portion is sorted!!\n");
	else
		ft_printf("portion is not sorted...\n");

//	ps.a.print = 1;
//	ps.b.print = 1;
//	sort_stacks(&ps);
	clear_stack(&ps.a);
	clear_stack(&ps.b);
	free(ps.sorted);
	return (0);
}
