/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:12:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/09 16:04:36 by nlegrand         ###   ########.fr       */
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
	int				i;
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

void	instruction_tests(t_stack *a, t_stack *b)
{
	show_stacks_status(a, b);
	show_stacks(a, b);
	push(b, a);
	//push(b, a);
	//push(b, a);
	//rot_both(a, b);
	//rot_both(a, b);
	//rot_both(a, b);
	//rot_both(a, b);
	//rot_both(a, b);
	//rot_both(a, b);
	//rot_both(a, b);
	//rrot_both(a, b);
	show_stacks(a, b);
	show_stacks_status(a, b);
}

int	is_sorted(t_stack *s)
{
	t_stack_list *curr;

	if (s->top == NULL || s->size == 0)
		return (ft_printf("this bitch empty! YEEEET!!!\n"), 0);
	curr = s->top;
	while (curr != s->top->prev) // should still work even with a list of size 1 because it is automatically sorted
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sort_three(t_stack *s)
{
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
	ft_printf("you got there?\n");
}

void	sort_big_stupid(t_stack *a, t_stack *b)
{
	(void)b;
	// BIG STUPID WILL DO TOO MANY INSTRUCTIONS FOR LISTS OF 1 OR 2

	int				i;
	t_stack_list	*min;
	int				min_i;
	t_stack_list	*curr;
	void			(*rotfun)(t_stack *s);

	while (a->size != 1)
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
	ft_printf("minimum -> %d\n", min->data);
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;

	if (is_sorted(a))
		((void)ft_printf("Stack is sorted!\n"));
	else
		ft_printf("Stack is NOT sorted...\n");

	if (a->size == 3)
	{
		ft_printf("Trying to sort 3 elements...\n");
		sort_three(a);
	}
	else
		sort_big_stupid(a, b);

	if (is_sorted(a))
		ft_printf("Stack is sorted!\n");
	else
		ft_printf("Stack is NOT sorted...\n");
}
