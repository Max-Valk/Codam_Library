/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 15:43:49 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/05 15:30:36 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_stack **a, t_stack **b, int stack_size)
{
	int		*sorted;

	sorted = stack_to_array(a);
	if (!sorted)
		return ;
	quicksort(sorted, 0, stack_size - 1);
	set_true_index(a, sorted);
	free (sorted);
	if (stack_size <= 120)
		sort_100(a, b, stack_size);
	else
		sort_500(a, b, stack_size);
}

void	set_true_index(t_stack **a, int *sorted_array)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->data != sorted_array[i])
			i++;
		tmp->true_index = i;
		tmp = tmp->next;
	}
}

void	proxy_move(t_stack **a, t_stack *move_num, int stack_a)
{
	int		mid_point;

	set_index(a);
	mid_point = ft_stack_size(*a) / 2;
	if (mid_point > move_num->index)
	{
		while ((*a)->true_index != move_num->true_index)
		{
			if (stack_a == 1)
				ft_ra(a);
			else
				ft_rb(a);
		}
	}
	else
	{
		while ((*a)->true_index != move_num->true_index)
		{
			if (stack_a == 1)
				ft_rra(a);
			else
				ft_rrb(a);
		}
	}
}

void	push_b_back(t_stack **a, t_stack **b)
{
	while (*b)
	{
		proxy_move(b, is_biggest(b), 0);
		ft_pa(a, b);
	}
}

void	sort_last_quart(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		proxy_move(a, is_lowest(a), 1);
		ft_pb(a, b);
	}
	sort_3(a);
}
