/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:10:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/29 17:37:58 by mvalk         ########   odam.nl         */
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
