/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_building.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:21:08 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/05 15:30:43 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack_new(int num)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->data = num;
	return (new_stack);
}

t_stack	*ft_stacklast(t_stack *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}

void	ft_stackadd_back(t_stack **front, t_stack *new)
{
	t_stack	*last_stack;

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

void	ft_stackadd_front(t_stack **front, t_stack *new)
{
	if (*front)
		(*front)->prev = new;
	new->next = (*front);
	new->prev = NULL;
	*front = new;
}

void	ft_delstack(t_stack *node)
{
	if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node = NULL;
	free (node);
}
