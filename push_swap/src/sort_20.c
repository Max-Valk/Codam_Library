/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_20.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 14:53:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/12 13:22:44 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_20(t_stack **a, t_stack **b)
{
	int		mid_point;
	int		stack_size;
	t_stack	*lowest;

	stack_size = ft_stack_size(*a);
	while (stack_size > 3)
	{
		set_index(a);
		lowest = is_lowest(a);
		mid_point = stack_size / 2;
		if (mid_point > lowest->index)
		{
			while ((*a)->data != lowest->data)
				ft_ra(a);
		}
		else
		{
			while ((*a)->data != lowest->data)
				ft_rra(a);
		}
		ft_pb(a, b);
		stack_size--;
	}
	sort_small(a, b);
	push_b_back(a, b);
}
