/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_10.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 14:53:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 14:16:06 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_10(stack **a, stack **b)
{
	int		mid_point;
	stack	*lowest;
	stack	*tmp;

	tmp = *a;
	while (ft_stack_size(a) > 3)
	{
		set_index(a);
		print_list(a);
		lowest = is_lowest(a);
		// printf("%i\n", lowest->data);
		printf("\n%i\n", tmp->data);
		mid_point = ft_stack_size(a) / 2;
		if (mid_point > lowest->index)
		{
			ft_printf("if_1 ok\n");
			while (*a && (*a)->data != lowest->data)
			{
				ft_ra(a);
				// (*a) = (*a)->next;
			}
		}
		else
		{
			ft_printf("else ok\n");
			while (*a && (*a)->data != lowest->data)
			{
				ft_rra(a);
				// tmp = tmp->next;
			}
		}
		ft_pb(a, b);
	}
	sort_3(a);
	while (*b)
		ft_pa(a, b);
}