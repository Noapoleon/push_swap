/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:36:44 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/19 08:57:44 by nlegrand         ###   ########.fr       */
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
	int	i;
	int	j;

	if (size == 0)
		return ;
	if (size > 2)
	{
		median = ps->sorted[left + size / 2 + size % 2 - 1];
		//ft_printf("median -------> %d\n", median);
		//ft_printf("median index -> %d\n", left + size / 2 + size % 2 - 1);
		//ft_printf("a->size laal -> %d\n", a->size);
		//ft_printf("b->size laal -> %d\n", b->size);
		//ft_printf("size laal ----> %d\n", size);
		i = 0;
		j = 0;
		while (i < size)
		{
			if (a->top->data <= median)
				push(b, a);
			else if (++j)
				rot(a);
			++i;
		}
		size -= j;
		//ft_printf("a->size alla -> %d\n", a->size);
		//ft_printf("b->size laal -> %d\n", b->size);
		//ft_printf("size alla ----> %d\n", size);
		//ft_printf("j ------------> %d\n", j);

		i = j;
		if (i != a->size)
			while (i--) // rotate back the stuff to the top // useless the first time in a or the first time in b, can be checked with size == ps->size or ps->size /2
				rrot(a);

		quicksort_a(ps, a, b, j, left + j); // i think size doesn't need to be +1 for odds because of the <= in the first while loop of this function
		quicksort_b(ps, a, b, size, left);
	}
	else if (size == 1)
		push(b, a);
	else if (size == 2 && a->top->data > a->top->next->data)
	{
		swap(a);
		push(b, a);
		push(b, a);
	}
}

void	quicksort_b(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left)
{
	int	median;
	int	i;
	int	j;

	if (size == 0)
		return ;
	if (size > 2)
	{
		median = ps->sorted[left + size / 2 + size % 2 - 1]; // didn't check if there's something to modify here
		ft_printf("median -------> %d\n", median);
		ft_printf("median index -> %d\n", left + size / 2 + size % 2 - 1);
		ft_printf("a->size laal -> %d\n", a->size);
		ft_printf("b->size laal -> %d\n", b->size);
		ft_printf("size laal ----> %d\n", size);
		i = 0;
		j = 0;
		while (i < size)
		{
			if (b->top->data >= median) // just dumbly inverted, didn't check at all
				push(a, b);
			else if (++j)
				rot(b);
			++i;
		}
		size -= j;
		ft_printf("a->size alla -> %d\n", a->size);
		ft_printf("b->size laal -> %d\n", b->size);
		ft_printf("size alla ----> %d\n", size);
		ft_printf("j ------------> %d\n", j);

		i = j;
		if (i != b->size)
			while (i--) // rotate back the stuff to the top // useless the first time in a or the first time in b, can be checked with size == ps->size or ps->size /2
				rrot(b);

		quicksort_b(ps, a, b, j, left); // i think size doesn't need to be +1 for odds because of the <= in the first while loop of this function
		quicksort_a(ps, a, b, size, left + size); // didn't give any thought to that
	}
	else if (size == 1)
		push(a, b);
	else if (size == 2 && b->top->data < b->top->next->data)
	{
		swap(b);
		push(a, b);
		push(a, b);
	}
}


//void	test_sort_stupid(t_push_swap *ps, t_stack *src, t_stack *dst, int n_swap, int left, int right)
//{
//	int	median;
//	int	i;
//	int	j;
//	
//	if (n_swap == 0)
//		return ;
//	if (n_swap > 2)
//	{
//		median = ps->sorted[left + n_swap / 2]; // change that // probably not right when treating other branches than the first one so fix that, this is gonna look weird if it doesn't make shit segfault
//		i = 0;
//		j = 0;
//		while (i < n_swap) // find closed inferior to median instead of doing like alguez
//		{
//			if (src->top->data < median)
//				push(dst, src);
//			else
//			{
////				push(dst, src);
////				rot(dst);
//				rot(src);
//				++j;
//			}
//			++i;
//		}
//		test_sort_stupid(ps, src, dst, n_swap / 2 + (n_swap % 2), left + n_swap / 2 + (n_swap % 2), right); // something about adding left when left changes, right now it's always 0 though
//		//test_sort_stupid(ps, src, dst, n_swap / 2 + (n_swap % 2), left + n_swap / 2 + (n_swap % 2), right); // something about adding left when left changes, right now it's always 0 though
//	}
//	else if (n_swap == 1 || n_swap == 2)
//	{
//		if (n_swap == 1)
//			rot(src);
//		else
//		{
//			if (src->top->data < src->top->next->data)
//				swap(src);
//			rot(src);
//			rot(src);
//		}
//	}
////	while (j--)
////	{
////		rrot(dst);
////		push(src, dst);
////	}
//	//test_sort_stupid(ps, dst, src, swap / 2, left, swap / 2);
//
////	if (n_swap > 2)
////	{
////		ft_printf("bitch\n");
//		(void)j;
////		test_sort_stupid(ps, dst, src, swap / 2, left, swap / 2);
//		test_sort_stupid(ps, src, dst, n_swap / 2 + (n_swap % 2), left + n_swap / 2 + (n_swap % 2), right); // something about adding left when left changes, right now it's always 0 though
////		while (j--)
////		{
////			rrot(src);
//////			push(src, dst);
////		}
////		test_sort_stupid(ps, dst, src, n_swap / 2, left, left + n_swap / 2); // something about adding left when left changes, right now it's always 0 though
////		test_sort_stupid(ps, dst, src, swap / 2, left + swap / 2, left + swap); // something about adding left when left changes, right now it's always 0 though
//		//test_sort_stupid(ps, dst, src, swap / 2, left, swap / 2);
//		//rotate something??
//		//j = 0;
//		//while (j++ != i)
//		//	rrot(src);
//		//test_sort_stupid(ps, dst, src, swap / 2, swap / 2, right);
//		//test_sort_stupid(ps, dst, src, swap / 2 + (swap % 2), swap / 2 + 1, right); // there might be a lot of other stuff with +/- 1 to tweak
//		//j = 0;
//		//while (j++ != i + 1)
//		//	rot(dst);
//		//test_sort_stupid(ps, dst, src, swap / 2, swap / 2 + 1, right); // there might be a lot of other stuff with +/- 1 to tweak
//		//test_sort_stupid(ps, dst, src, swap / 2 + 1??, swap / 2, right); // might a plus one here for odd numbers
////	}
////	else if (n_swap == 2)
////	{
////		ft_printf("coucou\n");
////		if (src->top->data < src->top->next->data)
////			swap(src);
////		rot(src);
////		rot(src);
////		push(src, dst);
////		push(src, dst);
////	}
////	else if (n_swap == 1)
////	{
//////		ft_printf("caca\n");
////		push(src, dst);
////	rot(src);
////	}
//}
