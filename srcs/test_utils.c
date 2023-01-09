/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:12:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/09 17:16:13 by nlegrand         ###   ########.fr       */
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
