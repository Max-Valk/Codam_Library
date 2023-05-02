/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/20 12:25:49 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_swap(char **input)
{
	int		stack_size;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (check_input_type(input) || dupe_check(input))
		return (error_exit());
	a = ft_make_list(input);
	if (!a)
		return (error_exit());
	if (is_sorted(&a))
		return (free_list(&a), 0);
	stack_size = ft_stack_size(a);
	if (stack_size <= 20)
		sort_small(&a, &b, stack_size);
	else
		sort_big(&a, &b, stack_size);
	return (free_list(&a), 0);
}

int	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**input;

	if (argc < 2)
		return (1);
	else if (argc == 2 && argv[1][0] == '\0')
		return (error_exit());
	else if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			return (1);
		if (push_swap(input))
			return (free_input(input), 1);
		return (free_input(input), 0);
	}
	else
	{
		input = &argv[1];
		push_swap(input);
	}
	return (0);
}
