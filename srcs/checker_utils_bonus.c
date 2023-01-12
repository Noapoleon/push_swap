/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:57 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 00:27:59 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Checks if stack list is sorted
int	is_sorted(t_stack *s)
{
	t_stack_list *curr;

	if (s->top == NULL || s->size == 0)
		return (0);
	curr = s->top;
	while (curr != s->top->prev)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}


// Goes through the operations chained list and executes each operation using 
// function pointers
void	do_ops(t_ops *ops)
{
	t_ops	*curr;

	curr = ops;
	while (curr != NULL)
	{
		if (curr->op_short != NULL)
			curr->op_short(curr->arg1);
		else
			curr->op_long(curr->arg1, curr->arg2);
		curr = curr->next;
	}
}

// Frees all elements of chained list of operations
void	clear_ops(t_ops *ops)
{
	// NOT TESTED AT ALL
	t_ops	*curr;
	t_ops	*tmp;

	curr = ops;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
}
