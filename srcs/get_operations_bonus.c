/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:45:07 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 07:54:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Reads standard input makes operations
int	get_operations(t_ops **ops, t_stack *a, t_stack *b)
{
	char	*line;
	t_ops	**curr;

	curr = ops;
	while (gnl_w(0, &line) != -1)
	{
		if (*line == '\n' || *line == '\0') // probably wont stop ctrl+d causing error
		{
			free(line);
			break ;
		}
		*curr = make_operation(line, a, b);
		if (*curr == NULL)
			return (clear_ops(*ops), free(line), -1); // free operations
		curr = &(*curr)->next;
		free(line);
	}
	*curr = NULL;
	return (0);
}

t_ops	*make_operation(char *line, t_stack *a, t_stack *b)
{
	t_ops		*tmp;
	const int	len = ft_strlen(line);

	tmp = malloc(sizeof(t_ops));
	if (tmp == NULL || len < 3)
		return (NULL);
	init_operation(tmp);
	if (line[len - 2] == 'a')
	{
		tmp->arg1 = a;
		tmp->arg2 = b;
	}
	else // not sure this will work for everything but the order shouldn't matter for ss, rr and rrr. need to check for push
	{
		tmp->arg1 = b;
		tmp->arg2 = a;
	}
	get_op_function(line, tmp);
	if (tmp->op_short == NULL && tmp->op_long == NULL)
		return (free(tmp), NULL);
	return (tmp);
}

void	get_op_function(char *line, t_ops *op)
{
	if (!ft_memcmp(line, "pa\n", 4) || !ft_memcmp(line, "pb\n", 4))
		op->op_long = &push;
	else if (!ft_memcmp(line, "sa\n", 4) || !ft_memcmp(line, "sb\n", 4))
		op->op_short = &swap;
	else if (!ft_memcmp(line, "ra\n", 4) || !ft_memcmp(line, "rb\n", 4))
		op->op_short = &rot;
	else if (!ft_memcmp(line, "rra\n", 5) || !ft_memcmp(line, "rrb\n", 5))
		op->op_short = &rrot;
	else if (!ft_memcmp(line, "rr\n", 4))
		op->op_long = &rot_both;
	else if (!ft_memcmp(line, "rrr\n", 5))
		op->op_long = &rrot_both;
	else if (!ft_memcmp(line, "ss\n", 4))
		op->op_long = &swap_both;
}

void	init_operation(t_ops *op)
{
	op->op_short = NULL;
	op->op_long = NULL;
	op->arg1 = NULL;
	op->arg2 = NULL;
	op->next = NULL;
}
