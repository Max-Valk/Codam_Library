/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_500.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 14:39:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/12 16:27:32 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	num_push(int pivot_num, int prev_pivot, t_stack **a, t_stack **b)
{
	if ((*b)->true_index > prev_pivot + ((pivot_num - prev_pivot) / 2))
	{
		if ((*a)->true_index > pivot_num)
			ft_rr(a, b);
		else
			ft_rb(b);
	}
}

int	new_pivot(int live_stack_size, int stack_size)
{
	int	pivot;

	pivot = live_stack_size * 0.8;
	pivot = stack_size - pivot;
	return (pivot);
}

void	sort_500(t_stack **a, t_stack **b, int stack_size)
{
	int		pivot_num;
	int		live_stack_size;
	int		prev_pivot;

	prev_pivot = 0;
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
				live_stack_size--;
				if ((*b) && (*b)->next)
					num_push(pivot_num, prev_pivot, a, b);
			}
			else
				ft_ra(a);
		}
		prev_pivot = pivot_num;
	}
	sort_20(a, b);
}
