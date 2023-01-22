/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:49:17 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/22 08:38:53 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fills stacks with parsed int values from argv
int	init_stacks(t_push_swap *ps, int *arr, int size)
{
	t_stack_list	**curr;
	t_stack_list	*prev;
	int				i;

	curr = &ps->a->top;
	prev = NULL;
	i = 0;
	while (i < size)
	{
		*curr = malloc(sizeof(t_stack_list));
		if (*curr == NULL)
			return (clear_stack(ps->a), -1); // not tested at all
		(*curr)->prev = prev;
		prev = *curr;
		(*curr)->data = arr[i++];
		(*curr)->next = NULL;
		curr = &((*curr)->next);
		++ps->a->size;
	}
	ps->a->top->prev = prev;
	prev->next = ps->a->top;
	return (0);
}

// Sets stack attributes to 0
void	zero_init_stack(t_stack *s, char name)
{
	s->name = name;
	s->top = NULL;
	s->size = 0;
	s->print = 0;
}

// Swap function for quicksort
static void	qs_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Sub-function for quicksort
// Returns index of pivot after having swapped it for it's correct position
static int	qs_partition(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
			qs_swap(&arr[++i], &arr[j]);
		++j;
	}
	qs_swap(&arr[++i], &arr[right]);
	return (i);
}

// Sorts an array recursively using a pivot
// Every number before the pivot is inferior and every number after the pivot is
// superior
void	quicksort(int *arr, int left, int right)
{
	int	pivot;

	if (left >= right)
		return ;
	pivot = qs_partition(arr, left, right);
	quicksort(arr, left, pivot - 1);
	quicksort(arr, pivot + 1, right);
}
