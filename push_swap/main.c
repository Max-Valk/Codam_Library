/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/16 13:51:23 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

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
	ft_reverse_rotate(&stack_1);
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
}