/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 15:14:44 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 16:07:11 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*index;
	int		size;

	index = *a;
	size = 0;
	while (index)
	{
		if (index->next)
		{
			if (index->data > index->next->data)
				return (0);
		}
		index = index->next;
		size++;
	}
	if (size == ft_stack_size(*a))
		return (1);
	else
		return (0);
}

int	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		ft_pb(a, b);
		sort_4(a, b);
	}
	else if (size == 5)
	{
		ft_pb(a, b);
		ft_pb(a, b);
		if ((*b)->data < (*b)->next->data)
			ft_sb(b);
		sort_5(a, b);
	}
	return (1);
}

t_stack	*is_lowest(t_stack **a)
{
	t_stack	*lowest;
	t_stack	*index;

	index = *a;
	lowest = *a;
	while (index)
	{
		if (index->data < lowest->data)
			lowest = index;
		index = index->next;
	}
	return (lowest);
}

t_stack	*is_biggest(t_stack **a)
{
	t_stack	*biggest;
	t_stack	*index;

	index = *a;
	biggest = *a;
	while (index)
	{
		if (index->data > biggest->data)
			biggest = index;
		index = index->next;
	}
	return (biggest);
}
