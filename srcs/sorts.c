/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 21:59:43 by nlegrand         ###   ########.fr       */
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

void	quicksort_a(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left)
{

	int	median;
	int	remain;
	int	i;

	if (size < 2 || is_ascending_portion(a->top, size))
		return ;
	if (size > 2)
	{
		if (size % 2) // 3??? I'm not sure it CAN end at size == 3 here, do the math again if there's another loop
			median = ps->sorted[left + size / 2];
		else
			median = ps->sorted[left + size / 2 - ((size / 2) % 2) - 1];
		remain = 0;
		i = 0;
		while (i < size)
		{
			if (a->top->data <= median)
				push(b, a);
			else if (++remain)
				rot(a);
			++i;
		}
		i = remain;
		if (i != a->size)
			while (i--) // rotate back the stuff to the top // useless the first time in a or the first time in b, can be checked with size == ps->size or ps->size /2
				rrot(a);
		quicksort_a(ps, a, b, remain, left + (size - remain));
		quicksort_b(ps, a, b, size - remain, left);
	}
	else if (a->top->data > a->top->next->data)
			swap(a);
}

void	quicksort_b(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left)
{
    int	median;
	int	remain;
	int	i;

	if (size == 0)
		return ;
	if (is_descending_portion(b->top, size))
	{
		i = size;
		while (i--)
			push(a, b);
	}
	else if (size > 2)
	{
		median = ps->sorted[left + size / 2 + ((size / 2) % 2)]; // didn't check if there's something to modify here
		remain = 0;
		i = 0;
		while (i < size)
		{
			if (b->top->data >= median)
				push(a, b);
			else if (++remain)
				rot(b);
			++i;
		}
		i = remain;
		if (remain != b->size)
			while (i--)
				rrot(b);
		quicksort_a(ps, a, b, size - remain, left + remain);
		quicksort_b(ps, a, b, remain, left);
	}
	else if (size == 2)
	{
		if (b->top->data < b->top->next->data)
			swap(b);
		push(a, b);
		push(a, b);
	}
}

int	is_ascending_portion(t_stack_list *s, int size)
{
	t_stack_list *curr;

	curr = s;
	while (--size)
	{
		if (curr->data > curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_descending_portion(t_stack_list *s, int size)
{
	t_stack_list *curr;

	curr = s;
	while (--size)
	{
		if (curr->data < curr->next->data)
			return (0);
		curr = curr->next;
	}
	return (1);
}
