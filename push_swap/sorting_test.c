/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 15:14:44 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 14:13:59 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(stack **a, int size)
{
	if (size == 2)
	{
		if ((*a)->data > (*a)->next->data)
			ft_sa(a);
		exit(0);
	}
}

int	is_sorted(stack **a)
{
	stack	*index;
	int		size;
	
	index = *a;
	size = 0;
	while (index)
	{
		if (index->next)
		{
			if (index->data	> index->next->data)
				return (0);
		}
		index = index->next;
		size++;
	}
	if (size == ft_stack_size(a))
		return (1);
	else
		return (0);
		
}

int	sort_size(stack **a, stack **b)
{
	int	size;

	if (is_sorted(a))
		return (1);
	size = ft_stack_size(a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		ft_pb(a, b);
		sort_4(a, b);
	}
	else if (size == 5)
	{
		ft_pb(a, b);
		ft_pb(a, b);
		if ((*b)->data < (*b)->next->data)
			ft_sb(b);
		sort_5(a, b);
	}
	return (1);
}

stack	*is_lowest(stack **a)
{
	stack	*lowest;
	
	lowest = *a;
	while (*a)
	{
		if ((*a)->data < lowest->data)
			lowest = (*a);
		*a = (*a)->next;
	}
	return (lowest);
}

// void	bubble_sort(stack **a, stack **b)
// {
// 	stack	*lowest;
// 	int 	lowest_data;
// 	int		rotate_dir;

// 	if (is_sorted(a))
// 		return ;
// 	lowest = is_lowest(a);
// 	rotate_dir = rotate_direction(&lowest);
// 	lowest_data = lowest->data;
// 	while ((*a)->next)
// 	{
// 		if (rotate_dir == -1)
// 		{
// 			if ((*a)->data == lowest_data)
// 			{
// 				ft_printf("error1_");
// 				ft_pb(a, b);
// 				ft_printf("error2_");
// 				lowest = is_lowest(a);
// 				ft_printf("error3_");
// 				lowest_data = lowest->data;
// 				ft_printf("error4_");
// 				rotate_dir = rotate_direction(&lowest);
// 			}
// 			if ((*a)->next)
// 				ft_ra(a);
// 		}
// 		else if (rotate_dir == 1)
// 		{
// 			if ((*a)->data == lowest_data)
// 			{
// 				ft_printf("error1");
// 				ft_pb(a, b);
// 				ft_printf("error2");
// 				lowest = is_lowest(a);
// 				ft_printf("error3");
// 				// print_list(lowest);
// 				lowest_data = lowest->data;
// 				ft_printf("error4");
// 				rotate_dir = rotate_direction(&lowest);
// 				ft_printf("error5");
// 			}
// 			else
// 				ft_rra(a);
// 		}
// 	}
// 	while (*b)
// 		ft_pa(a, b);
// }
