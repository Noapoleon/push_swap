/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/13 00:44:22 by nlegrand         ###   ########.fr       */
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

typedef struct s_stack		t_stack;
typedef struct s_stack_list	t_stack_list;
struct s_stack
{
	char			name;
	t_stack_list	*top;
	int				size;
	int				print;
};
struct s_stack_list
{
	t_stack_list	*prev;
	int				data;
	t_stack_list	*next;
};

// PUSH SWAP
void	sort_stacks(t_stack *a, t_stack *b);

// PARSER 1
int		setup_stacks(t_stack *a, t_stack *b, int ac, char **av);
int		get_stack_format(int *n_elem, int ac, char **av);
int		get_string_format(int *n_elem, char *str);
int		parse_ints(int	*tmp, int ac, char **av);
int		parse_int(int *n, char *nptr, int *j);
// PARSER 2
int		init_stacks(t_stack *a, t_stack *b, int *tmp, int size);
void	zero_init_stack(t_stack *s, char name);

// UTILS
void	clear_stack(t_stack *stack);

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

#endif
