/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 14:32:47 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/23 17:31:46 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(stack **a)
{
	if ((*a)->data > (*a)->next->data)
		ft_sa(a);
	exit(0);
}

void	sort_3(stack **a)
{
	stack	*last;

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

void	sort_4(stack **a, stack **b)
{
	stack	*last;

	// ft_pb(a, b);
	sort_3(a);
	last = ft_stacklast(*a);
	if ((*b)->data < (*a)->data)
		ft_pa(a, b);
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
	{
		ft_ra(a);
		ft_pa(a, b);
		ft_rra(a);
	}
	else if ((*b)->data > (*a)->data && (*b)->data < last->data)
	{
		ft_rra(a);
		ft_pa(a, b);
		ft_ra(a);
		ft_ra(a);
	}
	else
	{
		ft_pa(a, b);
		ft_ra(a);
	}
}

void	sort_5(stack **a, stack **b)
{
	stack	*last_prev;

	sort_4(a, b);
	last_prev = ft_stacklast(*a)->prev;
	if ((*b)->data < (*a)->data)
		ft_pa(a, b);
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
	{
		ft_ra(a);
		ft_pa(a, b);
		ft_rra(a);
	}
	else if ((*b)->data > (*a)->data && (*b)->data < last_prev->data)
	{
		ft_ra(a);
		ft_ra(a);
		ft_pa(a, b);
		ft_rra(a);
		ft_rra(a);
	}
	else
	{
		ft_rra(a);
		ft_pa(a, b);
		ft_ra(a);
		ft_ra(a);
	}
}