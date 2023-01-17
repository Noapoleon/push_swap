/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 23:44:34 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s)
{
	if (s->top->data < s->top->next->data
		&& s->top->next->data < s->top->prev->data)
		return ;
	if (s->top->data > s->top->next->data)
	{
		if (s->top->data < s->top->prev->data)
			return (swap(s));
		rot(s);
		if (s->top->data > s->top->next->data)
			swap(s);
		return ;
	}
	else if (s->top->data > s->top->prev->data)
		return (rrot(s));
	rrot(s);
	swap(s);
}

void	sort_big_stupid(t_stack *a, t_stack *b)
{
	int				i;
	t_stack_list	*min;
	int				min_i;
	t_stack_list	*curr;
	void			(*rotfun)(t_stack *s);

	while (a->size != 1) // get_min(t_stack *s, )
	{
		i = 0;
		min = a->top;
		min_i = 0;
		curr = min->next;
		while (i < a->size) // what if last one is pushed? will i go out of bounds and try to access the first one??
		{
			if (curr->data < min->data)
			{
				min = curr;
				min_i = i;
			}
			curr = curr->next;
			++i;
		}
		if (min_i * 2 <= a->size)
			rotfun = &rrot;
		else
			rotfun = &rot;
		while (a->top != min)
			rotfun(a);
		push(b, a);
	}
	while (b->size != 0)
		push(a, b);
}

int	get_min_dist(t_stack *s)
{
	t_stack_list	*curr;
	int				min;
	int				min_pos;
	int				pos;

	curr = s->top;
	min = curr->data;
	min_pos = 1;
	pos = 1;
	while (pos < s->size + 1)
	{
		if (curr->data < min)
		{
			min_pos = pos;
			min = curr->data;
		}
		curr = curr->next;
		++pos;
	}
	if (min_pos * 2 <= s->size) // +/-1 here maybe? i think not (visualize with trig circle)
		return (min_pos - 1);
	else
		return (min_pos - s->size - 1);
}

int	get_max_dist(t_stack *s)
{
	t_stack_list	*curr;
	int				max;
	int				max_pos;
	int				pos;

	curr = s->top;
	max = curr->data;
	max_pos = 1;
	pos = 1;
	while (pos < s->size + 1)
	{
		if (curr->data > max)
		{
			max_pos = pos;
			max = curr->data;
		}
		curr = curr->next;
		++pos;
	}
	if (max_pos * 2 <= s->size) // +/-1 here maybe? i think not (visualize with trig circle)
		return (max_pos - 1);
	else
		return (max_pos - s->size - 1);
}

void	set_rot_function(int min_dist, int max_dist, void (**rotfun)(t_stack *s)
		, int *limiter)
{
	const int	min_abs = ft_abs(min_dist);
	const int	max_abs = ft_abs(max_dist);

	if ((min_abs <= max_abs) && min_dist > 0)
		return ((*rotfun = rot), (void)(*limiter = min_abs));
	else if ((min_abs > max_abs) && max_dist > 0)
		return ((*rotfun = rot), (void)(*limiter = max_abs));
	*rotfun = rrot;
	if (min_abs <= max_abs)
		*limiter = min_abs;
	else
		*limiter = max_abs;
}

void	rot_closest_end(t_stack *s)
{
	// NO NEED TO RECALCULATE THE END THAT WON'T BE PUSHED SO FIND A WAY TO IMPLEMENT THAT, maybe static variables?
	const int	min_dist = get_min_dist(s); // this is gonna be a +/- 1 nightmare...
	const int	max_dist = get_max_dist(s); // same here
	void		(*rotfun)(t_stack *s);
	int			limiter;

	//ft_printf("min_dist -> %d\n", min_dist);
	//ft_printf("max_dist -> %d\n", max_dist);
	if (min_dist == 0 || max_dist == 0)
		return ;
	set_rot_function(min_dist, max_dist, &rotfun, &limiter);
	while (limiter != 0)
	{
		rotfun(s);
		--limiter;
	}
	// to avoid to recalculate maybe set something here for the next, like a -1 or 1 variable to say which one was used, needs to be static
}

void	sort_big_less_stupid_still_stupid(t_stack *a, t_stack *b)
{
	// TEST WITH STUFF HIGHER THAN 5 FOR NOW
	while (a->size != 0) // != 1 would suffice, actually it might cause issues in rot_closest_end when size is 1
	{
		rot_closest_end(a);
		if (b->top && b->top->data > a->top->data)
		{
			rot(b);
			push(b, a);
		}
		else
			push(b, a);

	}
	while (b->top->data < b->top->prev->data)
		rot(b);
	while (b->size != 0) // nope, needs rotate to half
	{
		push(a, b);
	}
}

//void	closest_below_median(

void	test_sort_stupid(t_push_swap *ps, t_stack *src, t_stack *dst, int swap, int left, int right)
{
	int	median;
	int	i;
	int	j;
	
	if (left >= right || swap == 0)
		return ;
	median = ps->sorted[left + swap / 2]; // change that // probably not right when treating other branches than the first one so fix that, this is gonna look weird if it doesn't make shit segfault
	i = 0;
	while (i < swap) // find closed inferior to median instead of doing like alguez
	{
		if (src->top->data < median)
			push(dst, src);
		else
			rot(src);
		++i;
	}

	if (swap >= 2)
	{
		//(void)j;
		test_sort_stupid(ps, dst, src, swap / 2, left, swap / 2);
		//rotate something??
		j = 0;
		while (j++ != i)
			rot(dst);
		//test_sort_stupid(ps, dst, src, swap / 2, swap / 2, right);
		test_sort_stupid(ps, dst, src, swap / 2 + (swap % 2), swap / 2 + 1, right); // there might be a lot of other stuff with +/- 1 to tweak
		j = 0;
		while (j++ != i + 1)
			rot(dst);
		//test_sort_stupid(ps, dst, src, swap / 2, swap / 2 + 1, right); // there might be a lot of other stuff with +/- 1 to tweak
		//test_sort_stupid(ps, dst, src, swap / 2 + 1??, swap / 2, right); // might a plus one here for odd numbers
	}
}
