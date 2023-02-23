/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 14:32:47 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 15:35:04 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_is_biggest(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_pa(a, b);
	ft_rra(a);
}

void	sort_2(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		ft_sa(a);
	exit(0);
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

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*last;

	sort_3(a);
	last = ft_stacklast(*a);
	if ((*b)->data < (*a)->data)
		ft_pa(a, b);
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
		second_is_biggest(a, b);
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

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*last_prev;

	sort_4(a, b);
	last_prev = ft_stacklast(*a)->prev;
	if ((*b)->data < (*a)->data)
		ft_pa(a, b);
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
		second_is_biggest(a, b);
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
