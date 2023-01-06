/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/04 18:40:40 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int *tmp, int size)
{
	t_stack_list	**curr;
	t_stack_list	*prev;
	int				i;

	zero_init_stack(a);
	zero_init_stack(b);
	curr = &a->top;
	prev = NULL;
	i = 0;
	while (i < size)
	{
		*curr = malloc(sizeof(t_stack_list));
		if (*curr == NULL)
			return (clear_stack(a), -1); // not tested at all
		(*curr)->prev = prev;
		prev = *curr;
		(*curr)->data = tmp[i++];
		(*curr)->next = NULL;
		curr = &((*curr)->next);
		++a->size;
	}
	a->top->prev = prev; // this for circle
	prev->next = a->top;
//	*curr = a->top; // added when removed double chaines
	return (0);
}

void	zero_init_stack(t_stack *stack)
{
	stack->top = NULL;
//	stack->bot = NULL;
	stack->size = 0;
}

// Clears the contents of a stack but doesn't need to free the stack variable
// itself  as in our situation it's not allocated
void	clear_stack(t_stack *s)
{
	// NEEDS TO BE MODIFIED FOR CIRCLE STACK
	t_stack_list	*curr;
	t_stack_list	*tmp;
	int				i;

	curr = s->top;
	i = 0;
	while (i++ < s->size) // or == to top i think not sure that would always work
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	s->top = NULL;
	s->size = 0;
}

//void	terminate_ps(t_stack *a, t_stack *b, int **tmp)
//{
//	clear_stack(a);
//	clear_stack(b);
//	free(tmp);
//}
