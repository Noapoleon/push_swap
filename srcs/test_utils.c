/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:12:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/04 19:08:14 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks_status(t_stack *a, t_stack *b)
{
	ft_printf("### a status ###\n");
	ft_printf("top addr: %p\n", a->top);
//	ft_printf("top prev addr %p\n", a->top->prev);
//	ft_printf("top prev data %d\n", a->top->prev->data);
//	ft_printf("bot addr: %p\n", a->bot);
	ft_printf("size: %d\n", a->size);
	ft_printf("################\n");
	ft_printf("### b status ###\n");
	ft_printf("top addr: %p\n", b->top);
//	ft_printf("bot addr: %p\n", b->bot);
	ft_printf("size: %d\n", b->size);
	ft_printf("################\n");
}
void	show_stacks(t_stack *a, t_stack *b)
{
	int	i;
	t_stack_list	*curra;
	t_stack_list	*currb;

	ft_printf("     a           b     \n");
	ft_printf("----------- -----------\n");
	i = 0;
	curra = a->top;
	currb = b->top;
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
			ft_printf("%-11d ", curra->data);
		else
			ft_printf("%11s ", "");
		if (i < b->size)
			ft_printf("%-11d\n", currb->data);
		else
			ft_printf("%11s\n", "");
		if (i < a->size)
			curra = curra->next;
		if (i < b->size)
			currb = currb->next;
		++i;
	}
	ft_printf("----------- -----------\n");
	ft_printf("     a           b     \n");
}

// Old
//void	show_stacks(int *a, int *b)
//{
//	(void)b;
//	int	i;
//
//	i = 0;
//	while (i < ac - 1)
//		ft_printf("%-11d x\n", a[i++]); // DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONT USE PRINTF IF I DECIDE TO MOVE THIS
//	ft_printf("----------- -----------\n");
//	ft_printf("     a           b     \n");
//}

void	push(t_stack *dst, t_stack *src)
{
	t_stack_list *pushing;

	if (src->size == 0) // useless but keep for debugging with a print
		return ((void)ft_printf("nothing to push\n"));
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
		return ((void)ft_printf("nothing to swap\n"));
	tmp = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp;
}

void	rot(t_stack *s)
{
	if (s->size < 2)
		return ((void)ft_printf("nothing to rot\n"));
	s->top = s->top->next;
}

void	rrot(t_stack *s)
{
	if (s->size < 2)
		return ((void)ft_printf("nothing to rrot\n"));
	s->top = s->top->prev;
}

void	instruction_tests(t_stack *a, t_stack *b)
{
	show_stacks_status(a, b);
	show_stacks(a, b);
	//swap(a);
	push(b, a);
	push(b, a);
	push(b, a);
	push(b, a);
	//push(b, a);
	rot(a);
	rot(a);
	rot(b);
	//rot(a);
	//rot(a);
	rrot(a);
	//rrot(a);
	swap(a);
	push(a, b);
	show_stacks(a, b);
	show_stacks_status(a, b);
}
