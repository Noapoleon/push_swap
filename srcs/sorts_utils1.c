/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:46:19 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 06:07:28 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pushed n times from src to dst
void	push_n(t_stack *dst, t_stack *src, int n)
{
	while (n--)
		push(dst, src);
}

// Rotates n times the specified list with the given rotation function
void	rot_n(t_stack *s, int n, void (*rotfun)(t_stack *s))
{
	while (n--)
		rotfun(s);
}

// Sorts small lists with push_swap instructions to limit number of recursions
// and reduce number of operations
// Used in quicksort_a only
int	smart_sort_a(t_stack *a, int size)
{
	if (size == 2 && a->top->data > a->top->next->data)
		return (swap(a), 1);
	if (size == 3)
		return (three_sort_a(a), 1);
	return (0);
}

// Sorts small lists with push_swap instructions to limit number of recursions
// and reduce number of operations
// Used in quicksort_b only
int	smart_sort_b(t_stack *b, int size)
{
	if (size == 2 && b->top->data < b->top->next->data)
		return (swap(b), 1);
	if (size == 3)
		return (three_sort_b(b), 1);
	return (0);
}
