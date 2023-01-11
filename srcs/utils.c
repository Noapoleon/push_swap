/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:35:31 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 18:50:06 by nlegrand         ###   ########.fr       */
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
