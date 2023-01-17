/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:52:36 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/17 19:03:19 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qs_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

void	quicksort(int *arr, int left, int right)
{
	int	pivot;

	if (left >= right)
		return ;
	pivot = qs_partition(arr, left, right);
	quicksort(arr, left, pivot - 1);
	quicksort(arr, pivot + 1, right);
}

void	alguez(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				qs_swap(&arr[i], &arr[j]);
			++j;
		}
		++i;
	}
}
