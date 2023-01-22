/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:46:19 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 09:36:23 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_n(t_stack *dst, t_stack *src, int n)
{
	while (n--)
		push(dst, src);
}

void	roll_back_remain(t_stack *s, int remain)
{
	if (remain != s->size)
		while (remain--) // rotate back the stuff to the top // useless the first time in a or the first time in b, can be checked with size == ps->size or ps->size /2
			rrot(s);
}

int	is_sorted_chunk(t_stack *s, int size)
{
	t_stack_list *curr;

	curr = s->top;
	if (s->name == 'a')
	{
		while (--size)
		{
			if (curr->data > curr->next->data)
				return (0);
			curr = curr->next;
		}
	}
	else
	{
		while (--size)
		{
			if (curr->data < curr->next->data)
				return (0);
			curr = curr->next;
		}
	}
	return (1);
}

// Sorts small lists with push_swap instructions to limit number of recursions
// and reduce number of operations
// Used in quicksort_a only
int	smart_sort_a(t_stack *a, t_stack *b, int size)
{
	(void)b;
	if (size == 2 && a->top->data > a->top->next->data)
		return (swap(a), 1);
	if (size == 3)
		return (three_sort_a(a), 1);
//	if (size == 4)
//		return (four_sort_a(a, b), 1);
	return (0);
}

int	smart_sort_b(t_stack *a, t_stack *b, int size)
{
	(void)a;
	if (size == 2 && b->top->data < b->top->next->data)
		return (swap(b), 1);
	if (size == 3)
		return (three_sort_b(b), 1);
//	if (size == 4)
//		return (four_sort_b(a, b), 1);
	return (0);
}
