/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/02 11:45:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int *tmp, int size)
{
	int				i;
	t_stack_list	**curr;

	zero_init_stack(a);
	zero_init_stack(b);
	i = 0;
	curr = &a->top;
	while (i < size)
	{
		*curr = malloc(sizeof(t_stack_list)); // PROTECT, make a list free function for stack
		// protect here
		(*curr)->data = tmp[i];
		curr = &((*curr)->next);
		//*curr->next = NULL; // probably useless thanks to the double pointer because when malloc fails it also sets the 'next' of the previous variable to NULL so we can go through it without having a bad pointer
		// check 'i' and compare to size to set 'bot' and 'bot_prev'
		++a->size;
		++i;
	}
	*curr = NULL;
	// the last curr's next variable shouldn't be initialized to NULL but it seems like it is (or maybe i just didn't do enough tests
	return (0);
}

void	zero_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bot_prev = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

void	terminate_ps(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
