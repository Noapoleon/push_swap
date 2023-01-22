/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 09:27:54 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_a(t_stack *a)
{
	if (a->top->data > a->top->next->data)
		swap(a);
	if (a->top->next->data > a->top->next->next->data)
	{
		rot(a);
		swap(a);
		rrot(a);
		if (a->top->data > a->top->next->data)
			swap(a);
	}
}

void	three_sort_b(t_stack *b)
{
	if (b->top->data < b->top->next->data)
		swap(b);
	if (b->top->next->data < b->top->next->next->data)
	{
		rot(b);
		swap(b);
		rrot(b);
		if (b->top->data < b->top->next->data)
			swap(b);
	}
}

void	four_sort_a(t_stack *a, t_stack *b)
{
	push_n(b, a, 2);
	if (a->top->data > a->top->next->data && b->top->data < b->top->next->data)
		swap_both(a, b);
	else if (a->top->data > a->top->next->data)
		swap(a);
	else if (b->top->data < b->top->next->data)
		swap(b);
	if (a->top->data > b->top->data)
		rot(a);
	if (a->top->data > b->top->data)
		rot(a);
	push(a, b);
	if (a->top->prev->data > b->top->data)
		rrot(a);
	if (a->top->prev->data > b->top->data)
		rrot(a);
	push(a, b);
}

void	four_sort_b(t_stack *a, t_stack *b)
{
	push_n(a, b, 2);
	if (a->top->data > a->top->next->data && b->top->data < b->top->next->data)
		swap_both(a, b);
	else if (a->top->data > a->top->next->data)
		swap(a);
	else if (b->top->data < b->top->next->data)
		swap(b);
	if (a->top->data > b->top->data)
		rot(a);
	if (a->top->data > b->top->data)
		rot(a);
	push(b, a);
	if (a->top->prev->data > b->top->data)
		rrot(a);
	if (a->top->prev->data > b->top->data)
		rrot(a);
	push(b, a);
}
