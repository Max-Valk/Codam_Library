/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 13:36:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/06 15:44:39 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_push(stack **stack_dst, stack **stack_src)
{
	stack	*src_next;

	if (*stack_src == NULL)
		return ;
	src_next = ((*stack_src)->next);
	ft_stackadd_front(stack_dst, *stack_src);
	if (src_next != NULL)
		src_next->prev = NULL;
	*stack_src = src_next;
}

void	ft_pa(stack **a, stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void	ft_pb(stack **a, stack **b)
{
	ft_push(b, a);
	ft_printf("pb\n");
}
/*
int main(void)
{
	stack *stack_1 = ft_stack_new(1);
	ft_stackadd_back(&stack_1, ft_stack_new(2));
	ft_stackadd_back(&stack_1, ft_stack_new(3));
	ft_stackadd_back(&stack_1, ft_stack_new(4));
	ft_stackadd_back(&stack_1, ft_stack_new(5));
	
	stack *stack_2 = ft_stack_new(5);
	ft_stackadd_back(&stack_2, ft_stack_new(6));
	ft_stackadd_back(&stack_2, ft_stack_new(7));
	ft_stackadd_back(&stack_2, ft_stack_new(8));
	ft_stackadd_back(&stack_2, ft_stack_new(9));
	
	ft_rotate(&stack_1);
	
	stack *head = stack_1;
	printf("size: %i\n\n", ft_stack_size(stack_1));
	while (head != NULL)
	{
		printf("\nNode\n");
		if (head->prev != NULL)
			printf("prev: %i\t", head->prev->data);
		else
			printf("prev:  ");
		printf("data: %i\t", head->data);
		if (head->next != NULL)
			printf("next: %i\n", head->next->data);
		head = head->next;
	}
	
	head = stack_2;
	printf("\n\nsize: %i\n\n", ft_stack_size(stack_2));
	while (head != NULL)
	{
		printf("\nNode\n");
		if (head->prev != NULL)
			printf("prev: %i\t", head->prev->data);
		else
			printf("prev:  ");
		printf("data: %i\t", head->data);
		if (head->next != NULL)
			printf("next: %i\n", head->next->data);
		head = head->next;
	}
	system("leaks -q a.out");
}*/
