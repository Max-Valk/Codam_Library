/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_500.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 14:39:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/16 17:09:44 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_pivot_500(int live_stack_size, int stack_size)
{
	int	pivot_num;

	if (live_stack_size > (stack_size * 0.875))
		pivot_num = (stack_size * 0.125) + 1;
	else if (live_stack_size >= (stack_size * 0.75))
		pivot_num = (stack_size * 0.25) + 1;
	else if (live_stack_size >= (stack_size * 0.625))
		pivot_num = (stack_size * 0.375) + 1;
	else if (live_stack_size >= (stack_size / 2))
		pivot_num = (stack_size / 2) + 1;
	else if (live_stack_size >= (stack_size * 0.375))
		pivot_num = (stack_size * 0.625) + 1;
	else if (live_stack_size >= (stack_size * 0.25))
		pivot_num = (stack_size * 0.75) + 1;
	else if (live_stack_size >= (stack_size * 0.125))
		pivot_num = (stack_size * 0.875) + 1;
	else if (live_stack_size >= (stack_size * 0.075))
		pivot_num = (stack_size * 0.925);
	else
		pivot_num = (stack_size * 0.96);
	return (pivot_num);
}

int new_pivot(int live_stack_size, int stack_size)
{
	int	pivot;

	pivot = live_stack_size * 0.82;
	pivot = stack_size - pivot;
	return (pivot);
}

int	sort_500(t_stack **a, t_stack **b, int stack_size)
{
	int		pivot_num;
	int		live_stack_size;
	int prev_pivot = 0;

	live_stack_size = stack_size;
	while (live_stack_size >= 20)
	{
		pivot_num = new_pivot(live_stack_size, stack_size);
		while (live_stack_size >= stack_size - pivot_num)
		{
			if ((*a)->true_index <= pivot_num)
			{
				proxy_move(a, *a, 1);
				ft_pb(a, b);
				if ((*b) && (*b)->next)
				{
					if ((*b)->true_index > prev_pivot + ((pivot_num - prev_pivot) / 2))
					{
						if ((*a)->true_index > pivot_num)
							ft_rr(a, b);
						else
							ft_rb(b);
					}
				}
			}
			else
				ft_ra(a);
			live_stack_size = ft_stack_size(*a);
		}
		prev_pivot = pivot_num;
	}
	sort_20(a, b);
	// sort_5(a, b);
	// sort_last_quart(a, b);
	// push_b_back(a, b);
	return (1);
}
