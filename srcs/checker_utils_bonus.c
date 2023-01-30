/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:57 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 08:12:41 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		else if (curr->op_long != NULL)
			curr->op_long(curr->arg1, curr->arg2);
		curr = curr->next;
	}
}

// Frees all elements of chained list of operations
void	clear_ops(t_ops *ops)
{
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
