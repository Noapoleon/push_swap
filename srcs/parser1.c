/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:10:06 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/29 10:11:49 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Parses argv into a stack of integers
// Stores parsed stack in variable 'a' and initializes both stacks
// Returns -1 on format error or malloc fail
int	setup_push_swap(t_push_swap *ps, int ac, char **av)
{
	int	*tmp;
	int	size;

	if (get_stack_format(&size, ac, av) == -1)
		return (-1);
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (-1);
	if (parse_ints(tmp, ac, av) == -1)
		return (free(tmp), -1);
	zero_init_stack(ps->a, 'a');
	zero_init_stack(ps->b, 'b');
	if (init_stacks(ps, tmp, size) == -1)
		return (free(tmp), -1);
	quicksort(tmp, 0, size - 1);
	ps->sorted = tmp;
	ps->size = size;
	return (0);
}

// Goes through argv and counts the numbers of the stack as well as detects
// format errors and returns -1 if one is encountered (doesn't detect duplicate
// numbers as they are not parsed in this step)
int	get_stack_format(int *size, int ac, char **av)
{
	int	i;

	*size = 0;
	i = 1;
	while (i < ac)
		if (get_string_format(size, av[i++]) == -1)
			return (-1);
	return (0);
}

// Sub-function of get_stack_format(), operates on a single string from argv
// Returns -1 when format error is encountered
int	get_string_format(int *size, char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			++i;
		if (str[i] == '+' || str[i] == '-')
			++i;
		if ((str[i] < '0' || str[i] > '9') || (!i && str[i] == '\0'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			++i;
		if (str[i] != '\0' && str[i] != ' ')
			return (-1);
		++(*size);
		while (str[i] && str[i] == ' ')
			++i;
	}
	return (0);
}

// Parses all ints from argv and and returns error in case of duplicates
int	parse_ints(int	*arr, int ac, char **av)
{
	int	i;
	int	j;
	int	c;
	int	dc;

	i = 1;
	c = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (parse_int(&arr[c], av[i] + j, &j) == -1)
				return (-1);
			dc = 0;
			while (dc < c)
				if (arr[dc++] == arr[c])
					return (-1);
			++c;
		}
		++i;
	}
	return (0);
}

// Parses a single integer and modifies the j pointer for next int in the same
// string
// Returning -1 here is probably useless as the format has been checked already
// but just in case I forgot something and need to debug later this will be
// useful
int	parse_int(int *n, char *nptr, int *j)
{
	int	i;

	if (ft_atois(n, nptr) == -1)
		return (-1);
	i = 0;
	while (nptr[i] == ' ')
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
		++i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		++i;
	while (nptr[i] == ' ')
		++i;
	*j += i;
	return (0);
}
