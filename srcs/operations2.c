/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:02:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/29 10:21:49 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	int	disabled;

	disabled = 0;
	if (a->print == 1)
	{
		a->print = 0;
		b->print = 0;
		disabled = 1;
	}
	if (disabled)
		ft_printf("ss\n");
	swap(a);
	swap(b);
	if (disabled)
	{
		a->print = 1;
		b->print = 1;
	}
}

void	rot_both(t_stack *a, t_stack *b)
{
	int	disabled;

	disabled = 0;
	if (a->print == 1)
	{
		a->print = 0;
		b->print = 0;
		disabled = 1;
	}
	if (disabled)
		ft_printf("rr\n");
	rot(a);
	rot(b);
	if (disabled)
	{
		a->print = 1;
		b->print = 1;
	}
}

void	rrot_both(t_stack *a, t_stack *b)
{
	int	disabled;

	disabled = 0;
	if (a->print == 1)
	{
		a->print = 0;
		b->print = 0;
		disabled = 1;
	}
	if (disabled)
		ft_printf("rrr\n");
	rrot(a);
	rrot(b);
	if (disabled)
	{
		a->print = 1;
		b->print = 1;
	}
}
