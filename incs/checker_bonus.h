/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <nlegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:56:10 by nlegrand          #+#    #+#             */
/*   Updated: 2023/01/11 21:42:58 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_BONUS_H
# define CHECK_BONUS_H

#include "push_swap.h"
#include "libft.h"

typedef struct s_ops	t_ops;
struct s_ops
{

	t_ops	*next;
};

// CHECKER
int	is_sorted(t_stack *s);

#endif
