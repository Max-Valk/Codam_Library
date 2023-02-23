/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 13:46:17 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 16:08:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	set_index(t_stack **a)
{
	t_stack	*tmp;
	int		index;

	tmp = *a;
	index = 0;
	while (tmp != NULL)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

int	ft_stack_size(t_stack *start)
{
	int	size;

	size = 0;
	while (start != NULL)
	{
		size++;
		start = start->next;
	}
	return (size);
}
