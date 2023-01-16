/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stack_new.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 16:21:08 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/13 16:28:12 by mvalk         ########   odam.nl         */
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
	new->next = *front;
	(*front)->prev = new;
	*front = new;
	new->prev = NULL;
	
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
	while (start)
	{
		size++;
		start = start->next;
	}
	return (size);
}

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
