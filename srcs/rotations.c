/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:04:59 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/29 09:13:02 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	init_rotations(t_rotations *rots)
//{
//	rots->count_total = 0;
//	rots->count_a = 0;
//	rots->count_b = 0;
//	rots->funptr_a = NULL;
//	rots->funptr_b = NULL;
//}

void	copy_rotations(t_rotations *rots, t_rotations *tmp)
{
	rots->count_total = tmp->count_total;
	rots->count_a = tmp->count_a;
	rots->count_b = tmp->count_b;
	rots->funptr_a = tmp->funptr_a;
	rots->funptr_b = tmp->funptr_b;
}

void	get_min(t_push_swap *ps, t_stack_list **min, int *min_index)
{
	t_stack_list	*curr;
	int				i;
	//t_stack_list	*min;
	//int				min_index;


	*min = ps->a->top;
	*min_index = 0;
	curr = ps->a->top->next;
	i = 1;
	while (i < ps->a->size)
	{
		if (curr->data < (*min)->data)
		{
			*min = curr;
			*min_index = i;
		}
		curr = curr->next;
		++i;
	}
}

int	get_index_a(t_push_swap *ps, t_stack_list *elem)
{
	t_stack_list	*min;
	int				min_index;
	int	i;
	t_stack_list	*curr;

	get_min(ps, &min, &min_index);
	if (elem->data < min->data || elem->data > min->prev->data)
		return (min_index);
	curr = ps->a->top;
	i = 0;
	while (i < ps->a->size)
	{
		if (curr->data > elem->data && curr->prev->data < elem->data)
			return (i);
		curr = curr->next;
		++i;
	}
	return (-1);
}

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

void	get_rotation(t_push_swap *ps, t_rotations *tmp, int index_b,
		t_stack_list *curr)
{
	const int	rev_index_b = ps->b->size - index_b;
	const int	index_a = get_index_a(ps, curr);
	const int	rev_index_a = ps->a->size - index_a;
	int			mov[4];

	mov[0] = ft_max(index_a, index_b);
	mov[1] = index_a + rev_index_b;
	mov[2] = ft_max(rev_index_a, rev_index_b);
	mov[3] = rev_index_a + index_b;
	tmp->count_total = ft_min(ft_min(mov[0], mov[1]), ft_min(mov[2], mov[3]));
	if (tmp->count_total == mov[0])
		set_rot(tmp, index_a, index_b, RA_RB);
	else if (tmp->count_total == mov[1])
		set_rot(tmp, index_a, rev_index_b, RA_RRB);
	else if (tmp->count_total == mov[2])
		set_rot(tmp, rev_index_a, rev_index_b, RRA_RRB);
	else
		set_rot(tmp, rev_index_a, index_b, RRA_RB);
}

void	get_least_rots(t_push_swap *ps, t_rotations *rots)
{
	t_rotations		tmp;
	t_stack_list	*curr;
	int				i;


	curr = ps->b->top;
	i = 0;
	while (i < ps->b->size)
	{
		get_rotation(ps, &tmp, i, curr);
		if (tmp.count_total < rots->count_total || i == 0)
			copy_rotations(rots, &tmp);
		if (rots->count_total == 0)
			break ;
		++i;
		curr = curr->next;
	}
}

void	do_least_rots(t_push_swap *ps, t_rotations *rots)
{
	void	(*funptr_both)(t_stack *a, t_stack *b);

	if (rots->funptr_a == rots->funptr_b)
	{
		if (rots->funptr_a == &rot)
			funptr_both = &rot_both;
		else
			funptr_both = &rrot_both;
		while (rots->count_a && rots->count_b)
		{
			funptr_both(ps->a, ps->b);
			--rots->count_a;
			--rots->count_b;
		}
	}
	while (rots->count_a--)
		rots->funptr_a(ps->a);
	while (rots->count_b--)
		rots->funptr_b(ps->b);
}

void	sort_closest(t_push_swap *ps)
{
	t_rotations	rots;

	//init_rotations(&rots); // might not need if get_least_moves is done properly
	get_least_rots(ps, &rots);
	do_least_rots(ps,  &rots);
	push(ps->a, ps->b);
}

