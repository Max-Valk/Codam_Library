/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_100.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:48:51 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 15:43:35 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	calculate_pivot_100(int live_stack_size, int stack_size)
{
	int	pivot_num;

	if (live_stack_size >= (stack_size * 0.75))
		pivot_num = (stack_size / 4) + 1;
	else if (live_stack_size >= stack_size / 2)
		pivot_num = (stack_size / 2) + 1;
	else
		pivot_num = (stack_size * 0.75) + 1;
	return (pivot_num);
}

int	sort_100(t_stack **a, t_stack **b, int stack_size)
{
	int		pivot_num;
	int		live_stack_size;

	live_stack_size = stack_size;
	while (live_stack_size >= stack_size / 4)
	{
		pivot_num = calculate_pivot_100(live_stack_size, stack_size);
		while (live_stack_size >= stack_size - pivot_num)
		{
			if ((*a)->true_index <= pivot_num)
			{
				proxy_move(a, *a, 1);
				ft_pb(a, b);
				if ((*b) && (*b)->next)
					if ((*b)->true_index > pivot_num - (stack_size / 8))
						ft_rb(b);
				live_stack_size = ft_stack_size(*a);
			}
			else
				ft_ra(a);
		}
	}
	sort_last_quart(a, b);
	push_b_back(a, b);
	return (1);
}
