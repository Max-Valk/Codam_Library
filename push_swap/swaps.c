/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swaps.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:25:52 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 17:45:32 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_swap(stack **head)
{
	stack	*elem_2;
	stack	*elem_3;

	if ((*head)->next == NULL || *head == NULL)
		return ;
	elem_2 = (*head)->next;
	if (elem_2->next)
	{
		elem_3 = elem_2->next;
		elem_3->prev = *head;
	}
	else
		elem_3 = NULL;
	elem_2->next = *head;
	elem_2->prev = NULL;
	*head = elem_2;
	elem_2->next->next = elem_3;
	elem_2->next->prev = elem_2;
}

void	ft_ss(stack **stack_a, stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

void	ft_sa(stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

/*
int main(void)
{
	stack *stack_1 = ft_stack_new(1);
	ft_stackadd_back(&stack_1, ft_stack_new(2));
	ft_stackadd_back(&stack_1, ft_stack_new(3));
	ft_stackadd_back(&stack_1, ft_stack_new(4));
	ft_stackadd_back(&stack_1, ft_stack_new(5));

	stack *head = stack_1;
	printf("size: %i\n\n", ft_stack_size(stack_1));

	ft_swap(&head);
	ft_swap(&head);
	while (head != NULL)
	{
		printf("\nNode\n");
		if (head->prev != NULL)
			printf("prev: %i\n", head->prev->data);
		printf("data: %i\n", head->data);
		if (head->next != NULL)
			printf("next: %i\n", head->next->data);
		head = head->next;
	}
	system("leaks -q a.out");
}*/
