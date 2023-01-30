/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction_sort3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:11:20 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 05:14:03 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rot(t_rotations *tmp, int count_a, int count_b, int mode)
{
	tmp->count_a = count_a;
	tmp->count_b = count_b;
	if (mode == RA_RB)
	{
		tmp->funptr_a = &rot;
		tmp->funptr_b = &rot;
	}
	else if (mode == RA_RRB)
	{
		tmp->funptr_a = &rot;
		tmp->funptr_b = &rrot;
	}
	else if (mode == RRA_RRB)
	{
		tmp->funptr_a = &rrot;
		tmp->funptr_b = &rrot;
	}
	else if (mode == RRA_RB)
	{
		tmp->funptr_a = &rrot;
		tmp->funptr_b = &rot;
	}
}

void	copy_rotations(t_rotations *rots, t_rotations *tmp)
{
	rots->count_total = tmp->count_total;
	rots->count_a = tmp->count_a;
	rots->count_b = tmp->count_b;
	rots->funptr_a = tmp->funptr_a;
	rots->funptr_b = tmp->funptr_b;
	rots->data = tmp->data;
}
