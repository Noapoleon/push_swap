/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:10 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/12 16:52:00 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

#include "push_swap.h"
#include "libft.h"

typedef struct s_ops	t_ops;
struct s_ops
{
	void	(*op_short)(t_stack *s);
	void	(*op_long)(t_stack *a, t_stack *b);
	t_stack	*arg1;
	t_stack	*arg2;
	t_ops	*next;
};

// GET OPERATIONS
int		get_operations(t_ops **ops, t_stack *a, t_stack *b);
t_ops	*make_operation(char *line, t_stack *a, t_stack *b);
void	get_op_function(char *line, t_ops *op);
void	init_operation(t_ops *op);
// CHECKER UTILS
int		is_sorted(t_stack *s);
void	do_ops(t_ops *ops);
void	clear_ops(t_ops *ops);



#endif
