/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_10.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 14:53:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/06 15:34:37 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_10(stack **a, stack **b)
{
	int		mid_point;
	stack	*lowest;

	while (ft_stack_size(*a) > 5)
	{
		set_index(a);
		lowest = is_lowest(a);
		mid_point = ft_stack_size(*a) / 2;
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
	}
	sort_size(a, b);
	while (*b)
		ft_pa(a, b);
}
