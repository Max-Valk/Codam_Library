/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_building.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:21:08 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 14:12:53 by mvalk         ########   odam.nl         */
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
	// new_stack->index = index;
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

int	ft_stack_size(stack **start)
{
	int size;
	stack	*index;

	index = *start;
	size = 0;
	while (index != NULL)
	{
		index = index->next;
		size++;
	}
	return (size);
}
/*
int ft_reverse_stack_size(stack *start)
{
	int	size;
	
	size = 0;
	print_list(&start);
	if (!start)
		return (0);
	while (start)
	{
		size++;
		start = start->prev;
	}
	return (size);
}

int	rotate_direction(stack **start)
{
	int direction = 0;
	ft_printf("reverse_error");
	int	size_to_head = ft_reverse_stack_size(*start);
	int	size = ft_stack_size(**start);
	

	if (size_to_head >= size)
		direction = 1;
	else if (size > size_to_head)
		direction = -1;
	return (direction);
}*/
// int main(void)
// {
// 	stack *stack_1 = ft_stack_new(1);
// 	ft_stackadd_back(&stack_1, ft_stack_new(2));
// 	ft_stackadd_back(&stack_1, ft_stack_new(3));
// 	ft_stackadd_back(&stack_1, ft_stack_new(4));
// 	ft_stackadd_back(&stack_1, ft_stack_new(5));
	
// 	stack *stack_2 = ft_stack_new(5);
// 	ft_stackadd_back(&stack_2, ft_stack_new(6));
// 	ft_stackadd_back(&stack_2, ft_stack_new(7));
// 	ft_stackadd_back(&stack_2, ft_stack_new(8));
// 	ft_stackadd_back(&stack_2, ft_stack_new(9));
	
// 	stack *head = stack_1;
// 	printf("size: %i\n\n", ft_stack_size(stack_1));
// 	while (head != NULL)
// 	{
// 		printf("\nNode\n");
// 		if (head->prev != NULL)
// 			printf("prev: %i\n", head->prev->data);
// 		printf("data: %i\n", head->data);
// 		if (head->next != NULL)
// 			printf("next: %i\n", head->next->data);
// 		head = head->next;
// 	}
// 	system("leaks -q a.out");
// }
