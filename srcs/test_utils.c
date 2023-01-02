/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:12:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 11:40:41 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks(t_stack *a, t_stack *b)
{
	(void)b;
	int	i;
	t_stack_list	*curra;
	t_stack_list	*currb;

	ft_printf("### a status ###\n");
	ft_printf("top addr:          %p\n", a->top);
	ft_printf("top bot_prev addr: %p\n", a->bot_prev);
	ft_printf("top bot addr:      %p\n", a->bot);
	ft_printf("size: %d\n", a->size);
	ft_printf("################\n");
	ft_printf("### b status ###\n");
	ft_printf("top addr:          %p\n", b->top);
	ft_printf("top bot_prev addr: %p\n", b->bot_prev);
	ft_printf("top bot addr:      %p\n", b->bot);
	ft_printf("size: %d\n", b->size);
	ft_printf("################\n");
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
		if (curra)
			curra = curra->next;
		if (currb)
			currb = currb->next;
		++i;
	}
	ft_printf("last a -> %p\n", curra);
	ft_printf("last b -> %p\n", currb);
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
