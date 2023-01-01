/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:11 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/01 20:31:15 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h> // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER

# define PSE_MALLOC_STACKS	"[ERROR] Failed to malloc stacks\n"
# define PSE_PARSE			"[ERROR] Failed to parse stack\n" // REMOOOOOOOOOOOVE LATER because i think i need to output "Error" only

typedef struct s_stack t_stack;
struct s_stack
{
	int		data;
	t_stack	*next;
};

int	parse_ints(int **a, int ac, char **av);
int	parse_int(int *a, char *nptr);


// TEST UTILS // REMOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOVE LATER
void	show_stacks(int *a, int *b, int ac);

#endif
