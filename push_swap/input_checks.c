/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:09:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/06 15:33:19 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	check_input_value(stack **head)
{
	stack	*stack_data;
	stack	*stack_checker;
	
	stack_data = *head;
	while (stack_data != NULL)
	{
		stack_checker = stack_data->next;
		while (stack_checker != NULL)
		{
			if (stack_data->data == stack_checker->data)
				error_exit();
			stack_checker = stack_checker->next;
		}
		stack_data = stack_data->next;
	}
	return (1);
}

int	check_input_type(char **argv, int arg_type)
{
	int	i;
	int	j;

	if (arg_type == 1)
		i = 1;
	else
		i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				error_exit();
			j++;
		}
		i++;
	}
	return (1);
}

stack	*ft_make_list(stack **head, char **argv, int arg_type)
{
	int		i;
	long	data;
	
	if (arg_type == 1)
		i = 1;
	else
		i = 0;
	while (argv[i] != NULL)
	{
		data = ft_atoi(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			error_exit();
		ft_stackadd_back(head, ft_stack_new(data));
		i++;
	}
	return (*head);
}
