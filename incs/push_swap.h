/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/07 13:14:44 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// DEBUUUUUUUUUUUUUUUUUUUUUUUUUUUUG ONLY, REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
// AND REPLACE ALL PRINTS TO "Error\n" on stderr
# define PSE_MALLOC_STACKS	"[ERROR] Failed to malloc stacks\n"
# define PSE_PARSE			"[ERROR] Failed to parse stack\n"
# define PSE_FORMAT			"[ERROR] Wrong argument format, not int\n"
# define PSE_DUPLICATE		"[ERROR] Duplicate arguments\n"

typedef struct s_stack		t_stack;
typedef struct s_stack_list	t_stack_list; // consider renaming
struct s_stack
{
	t_stack_list	*top;
	int				size; // added this variable in the circle branch AS A COMMENT to remind myself that this is an option
};
struct s_stack_list
{
	t_stack_list	*prev;
	int				data;
	t_stack_list	*next;
};

// PARSER
int		parse_ints(int **tmp, int ac, char **av);
int		parse_int(int *n, char *nptr);

// UTILS
int		init_stacks(t_stack *a, t_stack *b, int *tmp, int size);
void	zero_init_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

// OPERATIONS
void	push(t_stack *dst, t_stack *src);
void	swap(t_stack *s);
void	rot(t_stack *s);
void	rrot(t_stack *s);
// OPERATIONS 2
void	swap_both(t_stack *a, t_stack *b);
void	rot_both(t_stack *a, t_stack *b);
void	rrot_both(t_stack *a, t_stack *b);

// TEST UTILS // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
void	show_stacks_status(t_stack *a, t_stack *b);
void	show_stacks(t_stack *a, t_stack *b);
void	instruction_tests(t_stack *a, t_stack *b);
int		is_sorted(t_stack *s);
void	sort_stacks(t_stack *a, t_stack *b);

#endif
