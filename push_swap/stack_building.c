/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_building.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:21:08 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/06 15:47:15 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

stack	*ft_stack_new(int num)
{
	stack	*new_stack;

	new_stack = (stack *)ft_calloc(1, sizeof(stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = num;
	return (new_stack);
}

stack	*ft_stacklast(stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}

void ft_stackadd_back(stack **front, stack *new)
{
	stack	*last_stack;
	
	if (!new)
		return ;
	if (!*front)
	{
		*front = new;
		return ;
	}
	last_stack = ft_stacklast(*front);
	last_stack->next = new;
	new->prev = last_stack;
}

void ft_stackadd_front(stack **front, stack *new)
{
	if (*front)
		(*front)->prev = new;
	new->next = (*front);
	new->prev = NULL;
	*front = new;
}

void	ft_delstack(stack *node)
{
	if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node = NULL;
	free (node);
}

int	ft_stack_size(stack *start)
{
	int size;
	
	size = 0;
	while (start != NULL)
	{
		size++;
		start = start->next;
	}
	return (size);
}
