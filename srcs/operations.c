/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:50:43 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/09 17:19:09 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_stack_list	*pushing;

	if (src->size == 0) // useless but keep for debugging with a print
		return ((void)ft_printf("nothing to push\n")); // REMOOOOOOOOOOOOOOOOOOVE PRINT LATER
	ft_printf("p%c\n", src->name); // one line too long for function
	pushing = src->top;
	if (src->size-- == 1)
		src->top = NULL;
	else
	{
		src->top->prev->next = src->top->next;
		src->top->next->prev = src->top->prev;
		src->top = src->top->next;
	}
	if (dst->size++ == 0)
	{
		dst->top = pushing;
		dst->top->next = pushing;
		dst->top->prev = pushing;
		return ;
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

	if (s->size < 2) // put for debug only, but this might be useful
		return ((void)ft_printf("nothing to swap\n")); // REMOOOOOOOOOOOOOOOOOOVE PRINT LATER
	ft_printf("s%c\n", s->name);
	tmp = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp;
}

void	rot(t_stack *s)
{
	if (s->size < 2) // put for debug only, but this might be useful
		return ((void)ft_printf("nothing to rot\n")); // REMOOOOOOOOOOOOOOOOOOVE PRINT LATER
	ft_printf("r%c\n", s->name);
	s->top = s->top->next;
}

void	rrot(t_stack *s)
{
	if (s->size < 2) // put for debug only, but this might be useful
		return ((void)ft_printf("nothing to rrot\n")); // REMOOOOOOOOOOOOOOOOOOVE PRINT LATER
	ft_printf("rr%c\n", s->name);
	s->top = s->top->prev;
}
