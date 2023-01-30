/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:44:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 06:03:01 by nlegrand         ###   ########.fr       */
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
