/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/12 18:03:46 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	leak_chk(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	char	**input;

	atexit(leak_chk);
	if (argc < 2 || argv[1][0] == '\0')
		return (1);
	else if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			return (1);
		push_swap(input);
		return (free_input(input), 0);
	}
	else
	{
		input = &argv[1];
		push_swap(input);
	}
	return (0);
}

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
		return (0);
	stack_size = ft_stack_size(a);
	if (stack_size <= 20)
		sort_small(&a, &b);
	else
		sort_big(&a, &b, stack_size);
	return (free_list(&a), 0);
}

void	free_input(char **input)
{
	int	input_len;

	input_len = 0;
	while (input[input_len])
	{
		free (input[input_len]);
		input_len++;
	}
	free(input);
}

int	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	return (-1);
}
