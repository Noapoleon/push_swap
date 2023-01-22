/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 09:09:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s)
{
	if (s->top->data < s->top->next->data
		&& s->top->next->data < s->top->prev->data)
		return ;
	if (s->top->data > s->top->next->data)
	{
		if (s->top->data < s->top->prev->data)
			return (swap(s));
		rot(s);
		if (s->top->data > s->top->next->data)
			swap(s);
		return ;
	}
	else if (s->top->data > s->top->prev->data)
		return (rrot(s));
	rrot(s);
	swap(s);
}

void	quicksort_a(t_push_swap *ps, int size, int left)
{
	int	median;
	int	remain;
	int	i;

	if (size < 2 || is_sorted_chunk(ps->a, size) ||
		smart_sort_a(ps->a, ps->b, size))
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

	if (size == 0 || is_sorted_chunk(ps->b, size) ||
		smart_sort_b(ps->a, ps->b, size))
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
