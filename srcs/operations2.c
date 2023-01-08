/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:02:47 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/06 22:35:34 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rot_both(t_stack *a, t_stack *b)
{
	rot(a);
	rot(b);
}

void	rrot_both(t_stack *a, t_stack *b)
{
	rrot(a);
	rrot(b);
}
