/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 14:13:12 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arg_input;
	int		stack_size;
	stack	*a;
	stack	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		arg_input = ft_split(argv[1], ' ');
		check_input_type(arg_input, 0);
		a = ft_make_list(&a, arg_input, 0);
	}
	else
	{
		check_input_type(argv, 1);
		a = ft_make_list(&a, argv, 1);
	}
	check_input_value(&a);
	stack_size = ft_stack_size(&a);
	// print_list(&a);
	if (stack_size < 6)
		sort_size(&a, &b);
	else if (stack_size < 11)
		sort_10(&a, &b);
	set_index(&a);
	// print_list(&b);
	ft_printf("\nend of program\n");
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
		ft_printf("index: %i", list->index);
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