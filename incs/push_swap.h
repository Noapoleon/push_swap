/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/02/03 09:19:32 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define FRACT			3
# define RA_RB			0
# define RA_RRB			1
# define RRA_RRB		2
# define RRA_RB			3

typedef struct s_push_swap	t_push_swap;
typedef struct s_stack		t_stack;
typedef struct s_stack_list	t_stack_list;
typedef struct s_rotations	t_rotations;

struct s_stack_list
{
	t_stack_list	*prev;
	int				data;
	t_stack_list	*next;
};
struct s_stack
{
	char			name;
	t_stack_list	*top;
	int				size;
	int				print;
};
struct s_push_swap
{
	int		*sorted;
	int		size;
	t_stack	*a;
	t_stack	*b;
};
struct	s_rotations
{
	int		count_total;
	int		count_a;
	int		count_b;
	void	(*funptr_a)(t_stack *s);
	void	(*funptr_b)(t_stack *s);
	int		data;
};

// PUSH SWAP
void	sort_stacks(t_push_swap *ps);

// PARSER 1
int		setup_push_swap(t_push_swap *ps, int ac, char **av);
int		get_stack_format(int *size, int ac, char **av);
int		get_string_format(int *size, char *str);
int		parse_ints(int	*tmp, int ac, char **av);
int		parse_int(int *n, char *nptr, int *j);
// PARSER 2
int		init_stacks(t_push_swap *ps, int *tmp, int size);
void	zero_init_stack(t_stack *s, char name);
void	quicksort(int *arr, int left, int right);

// UTILS
void	clear_stack(t_stack *stack);
int		is_sorted_stack(t_stack *s);
int		is_sorted_array(int *arr, int size);

// OPERATIONS
void	push(t_stack *dst, t_stack *src);
void	swap(t_stack *s);
void	rot(t_stack *s);
void	rrot(t_stack *s);
void	pop(t_stack *s);
// OPERATIONS 2
void	swap_both(t_stack *a, t_stack *b);
void	rot_both(t_stack *a, t_stack *b);
void	rrot_both(t_stack *a, t_stack *b);

// SMALL SORTS
void	sort_three(t_stack *s);
void	sort_four_five(t_push_swap *ps);

// QUICK SORT
void	quicksort_a(t_push_swap *ps, int size, int left);
void	quicksort_b(t_push_swap *ps, int size, int left);
void	roll_back_remain(t_stack *s, int remain);
int		is_sorted_chunk(t_stack *s, int size);

// FRACTION SORT 1
void	fraction_sort(t_push_swap *ps);
void	split_list_fractions(t_push_swap *ps, int og_size, int left, int recu);
void	filter_fractions(t_push_swap *ps, int og_size, int splits[2]);
void	rotate_to_min(t_push_swap *ps);
void	sort_closest(t_push_swap *ps);
// FRACTION SORT 2
void	do_least_rots(t_push_swap *ps, t_rotations *rots);
void	get_least_rots(t_push_swap *ps, t_rotations *rots);
void	get_rotation(t_push_swap *ps, t_rotations *tmp, int index_b,
			t_stack_list *curr);
int		get_index_a(t_push_swap *ps, t_stack_list *elem);
void	get_min(t_push_swap *ps, t_stack_list **min, int *min_index);
// FRACTION SORT 3
void	set_rot(t_rotations *tmp, int count_a, int count_b, int mode);
void	copy_rotations(t_rotations *rots, t_rotations *tmp);

// SORTS UTILS
void	push_n(t_stack *dst, t_stack *src, int n);
void	rot_n(t_stack *s, int n, void (*rotfun)(t_stack *s));
int		smart_sort_a(t_stack *a, int size);
int		smart_sort_b(t_stack *b, int size);
// SORT UTILS 2
void	three_sort_a(t_stack *a);
void	three_sort_b(t_stack *b);

#endif
