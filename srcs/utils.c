/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/03 10:50:17 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int *tmp, int size)
{
	int				i;
	t_stack_list	**curr;
	t_stack_list	*prev;

	zero_init_stack(a);
	zero_init_stack(b);
	i = 0;
	curr = &a->top;
	prev = NULL;
	while (i < size)
	{
		*curr = malloc(sizeof(t_stack_list));
		if (*curr == NULL)
			return (clear_stack(a), -1); // not tested at all
		(*curr)->prev = prev;
		prev = *curr;
		(*curr)->data = tmp[i];
		printf("data -> %d\n", (*curr)->data);
		(*curr)->next = NULL;
		curr = &((*curr)->next);
		// check 'i' and compare to size to set 'bot' and 'bot_prev'
		++a->size;
		++i;
	}
	a->bot = prev; // not tested:wa
	return (0);
}

void	zero_init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

// Clears the contents of a stack but doesn't need to free the stack variable
// itself  as in our situation it's not allocated
void	clear_stack(t_stack *stack)
{
	t_stack_list	*curr;
	t_stack_list	*tmp;

	curr = stack->top;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	// rest
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

//void	terminate_ps(t_stack *a, t_stack *b, int **tmp)
//{
//	clear_stack(a);
//	clear_stack(b);
//	free(tmp);
//}
