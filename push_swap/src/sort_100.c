/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_100.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:48:51 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/12 13:46:48 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	calculate_pivot_101(int live_stack_size, int stack_size)
{
	int	pivot;

	pivot = live_stack_size * 0.75;
	pivot = stack_size - pivot;
	return (pivot);
}

void	sort_100(t_stack **a, t_stack **b, int stack_size)
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
				live_stack_size--;
				if ((*b) && (*b)->next)
					if ((*b)->true_index > pivot_num - (stack_size / 8))
						ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
	sort_20(a, b);
}
