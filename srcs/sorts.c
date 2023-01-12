/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/12 03:46:48 by nlegrand         ###   ########.fr       */
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

void	sort_big_stupid(t_stack *a, t_stack *b)
{
	int				i;
	t_stack_list	*min;
	int				min_i;
	t_stack_list	*curr;
	void			(*rotfun)(t_stack *s);

	while (a->size != 1) // get_min(t_stack *s, )
	{
		i = 0;
		min = a->top;
		min_i = 0;
		curr = min->next;
		while (i < a->size) // what if last one is pushed? will i go out of bounds and try to access the first one??
		{
			if (curr->data < min->data)
			{
				min = curr;
				min_i = i;
			}
			curr = curr->next;
			++i;
		}
		if (min_i * 2 <= a->size)
			rotfun = &rrot;
		else
			rotfun = &rot;
		while (a->top != min)
			rotfun(a);
		push(b, a);
	}
	while (b->size != 0)
		push(a, b);
}
