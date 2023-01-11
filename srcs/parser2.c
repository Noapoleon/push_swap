/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:49:17 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 19:03:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fills stacks with parsed int values from argv
int	init_stacks(t_stack *a, t_stack *b, int *tmp, int size)
{
	t_stack_list	**curr;
	t_stack_list	*prev;
	int				i;

	zero_init_stack(a, 'a');
	zero_init_stack(b, 'b');
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
void	zero_init_stack(t_stack *s, char name)
{
	s->name = name;
	s->top = NULL;
	s->size = 0;
}
