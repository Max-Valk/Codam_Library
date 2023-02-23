/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/14 15:54:37 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		stack_size;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (!check_input_type(argv, argc) || !dupe_check(argv))
		return (error_exit());
	a = ft_make_list(&a, argv);
	if (!a)
		return (error_exit());
	if (is_sorted(&a))
		return (0);
	stack_size = ft_stack_size(a);
	if (stack_size <= 5)
		sort_small(&a, &b);
	else if (stack_size <= 20)
		sort_20(&a, &b);
	else
		return (sort_big(&a, &b, stack_size));
	return (0);
}

int	error_exit(void)
{
	ft_printf("Error\n");
	return (-1);
}

// void	print_list(stack **head)
// {
// 	stack *list;

// 	list = *head;
// 	while (list != NULL)
// 	{
// 		ft_printf("\nNode\n");
// 		ft_printf("data: %i\t", list->data);
// 		ft_printf("true_index: %i", list->true_index);
// 		list = list->next;
// 	}
// }

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
