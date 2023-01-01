/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:12:28 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/01 20:36:40 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks(int *a, int *b, int ac)
{
	(void)b;
	int	i;

	i = 0;
	while (i < ac - 1)
		ft_printf("%-11d x\n", a[i++]); // DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOONT USE PRINTF IF I DECIDE TO MOVE THIS
	ft_printf("----------- -----------\n");
	ft_printf("     a           b     \n");
}
