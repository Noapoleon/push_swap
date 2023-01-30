/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:07:55 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 06:27:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_push_swap *ps, int size, int left)
{
	int	median;
	int	remain;
	int	i;

	if (size < 2 || is_sorted_chunk(ps->a, size)
		|| smart_sort_a(ps->a, size))
		return ;
	if (size % 2)
		median = ps->sorted[left + size / 2];
	else
		median = ps->sorted[left + size / 2 - ((size / 2) % 2) - 1];
	remain = 0;
	i = 0;
	while (i < size)
	{
		if (ps->a->top->data <= median)
			push(ps->b, ps->a);
		else if (++remain)
			rot(ps->a);
		++i;
	}
	roll_back_remain(ps->a, remain);
	quicksort_a(ps, remain, left + (size - remain));
	quicksort_b(ps, size - remain, left);
}

void	quicksort_b(t_push_swap *ps, int size, int left)
{
	int	median;
	int	remain;
	int	i;

	if (size == 0 || is_sorted_chunk(ps->b, size)
		|| smart_sort_b(ps->b, size))
		return (push_n(ps->a, ps->b, size));
	median = ps->sorted[left + size / 2 + ((size / 2) % 2)];
	remain = 0;
	i = 0;
	while (i < size)
	{
		if (ps->b->top->data >= median)
			push(ps->a, ps->b);
		else if (++remain)
			rot(ps->b);
		++i;
	}
	roll_back_remain(ps->b, remain);
	quicksort_a(ps, size - remain, left + remain);
	quicksort_b(ps, remain, left);
}

void	roll_back_remain(t_stack *s, int remain)
{
	if (remain != s->size)
		while (remain--)
			rrot(s);
}

int	is_sorted_chunk(t_stack *s, int size)
{
	t_stack_list	*curr;

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
