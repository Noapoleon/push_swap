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
	ft_printf("bot addr: %p\n", a->bot);
	ft_printf("################\n");
	ft_printf("### b status ###\n");
	ft_printf("top addr: %p\n", b->top);
	ft_printf("bot addr: %p\n", b->bot);
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
	while (curra || currb)
	{
		if (curra != NULL)
			ft_printf("%-11d ", curra->data);
		else
			ft_printf("%11s ", "");
		if (currb != NULL)
			ft_printf("%-11d\n", currb->data);
		else
			ft_printf("%11s\n", "");
		if (curra)
			curra = curra->next;
		if (currb)
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
	// Dont forget to change top and bot pointers approprietly when size is
	// is small, like 0, 1 or 2
	t_stack_list *pushing;

	if (src->top == NULL) // useless but keep for debugging with a print
		return (void)(ft_printf("ya plus rien\n"));
	pushing = src->top;
	src->top = src->top->next;
	if (src->top == NULL)
		src->bot = NULL;
	pushing->next = dst->top;
	dst->top = pushing;
	if (dst->top->next == NULL)
		dst->bot = dst->top;
}

void	instruction_tests(t_stack *a, t_stack *b)
{
	show_stacks_status(a, b);
	push(a, b);
	push(a, b);
	push(a, b);
	push(a, b);
	push(b, a);
	show_stacks(a, b);
	show_stacks_status(a, b);
}
