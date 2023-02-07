/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/07 13:29:19 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*sorted;
	int		stack_size;
	stack	*a;
	stack	*b;

	b = NULL;
	a = NULL;
	sorted = NULL;
	if (argc < 2)
		return (1);
	if (argc >= 2)
	{
		check_input_type(argv, 1);
		a = ft_make_list(&a, argv, 1);
		check_input_value(&a);
	}
	else
		error_exit();
	stack_size = ft_stack_size(a);
	if (stack_size <= 5)
		sort_size(&a, &b);
	else if (stack_size <= 10)
		sort_10(&a, &b);
	else if (stack_size <= 500)
	{
		sorted = stack_to_array(&a);
		quicksort(sorted, 0, stack_size - 1);
		set_true_index(&a, sorted);
		if (stack_size <= 100)
			sort_100(&a, &b, stack_size);
		else
			sort_500(&a, &b, stack_size);
	}
	return (0);
}

void	print_list(stack **head)
{
	stack *list;

	list = *head;
	while (list != NULL)
	{
		ft_printf("\nNode\n");
		ft_printf("data: %i\t", list->data);
		ft_printf("true_index: %i", list->true_index);
		list = list->next;
	}
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
	
	stack_2 = NULL;
	ft_pb(&stack_1, &stack_2);
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
	system("leaks -q push_swap");
}
*/
