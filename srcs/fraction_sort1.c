/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction_sort1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 04:59:20 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/30 06:27:11 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fraction_sort(t_push_swap *ps)
{
	split_list_fractions(ps, ps->a->size, 0, 1);
	sort_three(ps->a);
	while (ps->b->size != 0)
		sort_closest(ps);
	rotate_to_min(ps);
}

void	split_list_fractions(t_push_swap *ps, int og_size, int left, int recu)
{
	int	splits[2];

	splits[0] = ps->sorted[left + (og_size / (FRACT - recu + 1)) - 1];
	splits[1] = ps->sorted[left + (og_size / (FRACT - recu + 1)) * 2 - 1];
	filter_fractions(ps, og_size, splits);
	if (recu + 1 <= FRACT && ps->a->size > 3)
		split_list_fractions(ps, ps->a->size, ps->b->size, recu + 1);
}

void	filter_fractions(t_push_swap *ps, int og_size, int splits[2])
{
	int	rots;
	int	i;

	rots = 0;
	i = 0;
	while (i++ < og_size && ps->a->size > 3)
	{
		if (ps->a->top->data <= splits[0] && ++rots)
			push(ps->b, ps->a);
		else if (ps->a->top->data <= splits[1])
		{
			rot_n(ps->b, rots, &rot);
			rots = 0;
			push(ps->b, ps->a);
		}
		else if (rots && rots--)
			rot_both(ps->a, ps->b);
		else
			rot(ps->a);
	}
	if (rots)
		rot_n(ps->b, rots, &rot);
}

void	rotate_to_min(t_push_swap *ps)
{
	t_stack_list	*min;
	int				min_index;

	get_min(ps, &min, &min_index);
	if (min_index <= ps->a->size / 2)
		rot_n(ps->a, min_index, &rot);
	else
		rot_n(ps->a, ps->a->size - min_index, &rrot);
}

void	sort_closest(t_push_swap *ps)
{
	t_rotations	rots;

	get_least_rots(ps, &rots);
	do_least_rots(ps, &rots);
	push(ps->a, ps->b);
}
