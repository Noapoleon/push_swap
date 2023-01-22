/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:02:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 09:20:36 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	a->print = 0;
	b->print = 0;
	ft_printf("ss\n");
	swap(a);
	swap(b);
	a->print = 1;
	b->print = 1;
}

void	rot_both(t_stack *a, t_stack *b)
{
	a->print = 0;
	b->print = 0;
	ft_printf("rr\n");
	rot(a);
	rot(b);
	a->print = 1;
	b->print = 1;
}

void	rrot_both(t_stack *a, t_stack *b)
{
	a->print = 0;
	b->print = 0;
	ft_printf("rrr\n");
	rrot(a);
	rrot(b);
	a->print = 1;
	b->print = 1;
}
