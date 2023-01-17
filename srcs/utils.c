/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 16:02:05 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Checks that the given stack is sorted in ascending order
int	is_sorted_stack(t_stack *s)
{
	t_stack_list *curr;

	if (s == NULL || s->top == NULL || s->size == 0)
		return (0);
	curr = s->top;
	while (curr != s->top->prev) // should still work even with a list of size 1 because it is automatically sorted
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

// Checks that the given arr is sorted in ascending order
int	is_sorted_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (arr[i - 1] > arr[i])
			return (0);
	return (1);
}

