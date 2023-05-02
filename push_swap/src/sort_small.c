/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 14:32:47 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/20 12:27:35 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_small(t_stack **a, t_stack **b, int stack_size)
{
	int		mid_point;
	t_stack	*lowest;

	if (stack_size == 2)
		return (sort_2(a));
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
	sort_3(a);
	push_b_back(a, b);
}

void	sort_2(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		ft_sa(a);
}

void	sort_3(t_stack **a)
{
	t_stack	*last;

	last = ft_stacklast(*a);
	if ((*a)->data > (*a)->next->data && (*a)->next->data < last->data)
	{
		if ((*a)->data > last->data)
			ft_ra(a);
		else
			ft_sa(a);
	}
	else if ((*a)->data > (*a)->next->data && (*a)->next->data > last->data)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > last->data)
	{
		if ((*a)->data < last->data)
		{
			ft_sa(a);
			ft_ra(a);
		}
		else
			ft_rra(a);
	}
}
