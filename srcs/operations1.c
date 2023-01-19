/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:50:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/18 23:49:22 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_stack_list	*pushing;

	if (src->size == 0)
		return ;
	if (src->print && dst->print)
		ft_printf("p%c\n", dst->name);
	pushing = src->top;
	pop(src);
	if (dst->size++ == 0)
	{
		pushing->next = pushing;
		pushing->prev = pushing;
		return ((void)(dst->top = pushing));
	}
	pushing->next = dst->top;
	pushing->prev = dst->top->prev;
	dst->top->prev->next = pushing;
	dst->top->prev = pushing;
	dst->top = pushing;
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	if (s->print)
		ft_printf("s%c\n", s->name);
	tmp = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp;
}

void	rot(t_stack *s)
{
	if (s->size < 2)
		return ;
	if (s->print)
		ft_printf("r%c\n", s->name);
	s->top = s->top->next;
}

void	rrot(t_stack *s)
{
	if (s->size < 2)
		return ;
	if (s->print)
		ft_printf("rr%c\n", s->name);
	s->top = s->top->prev;
}

void	pop(t_stack *s)
{
	if (s->size == 0)
		return ;
	if (--s->size == 0)
		s->top = NULL;
	else
	{
		s->top->prev->next = s->top->next;
		s->top->next->prev = s->top->prev;
		s->top = s->top->next;
	}
}
