/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/21 21:59:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define PRINT_OP		1
# define NO_PRINT_OP	0

typedef struct s_push_swap	t_push_swap;
typedef struct s_stack		t_stack;
typedef struct s_stack_list	t_stack_list;
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
	t_stack	a;
	t_stack	b;
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

// SORTS
void	sort_three(t_stack *s);
void	sort_big_stupid(t_stack *a, t_stack *b);
void	sort_big_less_stupid_still_stupid(t_stack *a, t_stack *b);
void	quicksort_a(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left);
void	quicksort_b(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left);
int		is_ascending_portion(t_stack_list *s, int size);
int		is_descending_portion(t_stack_list *s, int size);
//void	quicksort_a(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left, int right);
//void	quicksort_b(t_push_swap *ps, t_stack *a, t_stack *b, int size, int left, int right);
//void	test_sort_stupid(t_push_swap *ps, t_stack *a, t_stack *b, int swap, int left, int right);

// TEST // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
void	quicksort(int *arr, int left, int right);
void	alguez(int *arr, int size);

#endif
