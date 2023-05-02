/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_building.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:21:08 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/19 14:13:04 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

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

t_stack	*ft_make_list(char **input)
{
	int		i;
	long	data;
	t_stack	*head;
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	head = NULL;
	i = 0;
	while (input[i] != NULL)
	{
		data = ft_atoi(input[i]);
		if (data > INT_MAX || data < INT_MIN)
			return (free_list(&head), NULL);
		tmp_stack = ft_stack_new(data);
		if (!tmp_stack)
			return (free_list(&head), NULL);
		ft_stackadd_back(&head, tmp_stack);
		i++;
	}
	return (head);
}
