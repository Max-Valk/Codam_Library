/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 15:14:44 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/20 13:33:28 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
