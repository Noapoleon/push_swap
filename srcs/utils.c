/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/09 17:14:21 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fills stacks with parsed int values from argv
int	init_stacks(t_stack *a, t_stack *b, int *tmp, int size)
{
	t_stack_list	**curr;
	t_stack_list	*prev;
	int				i;

	init_stack(a, 'a');
	init_stack(b, 'b');
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
	a->top->prev = prev;
	prev->next = a->top;
	return (0);
}

// Sets stack attributes to 0
void	init_stack(t_stack *s, char name)
{
	s->name = name;
	s->top = NULL;
	s->size = 0;
}

// Clears the contents of a stack but doesn't need to free the stack variable
// itself  as in our situation it's not allocated
void	clear_stack(t_stack *s)
{
	t_stack_list	*curr;
	t_stack_list	*tmp;
	int				i;

	curr = s->top;
	i = 0;
	while (i++ < s->size)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	s->top = NULL;
	s->size = 0;
}
