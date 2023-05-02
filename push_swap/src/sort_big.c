/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 15:43:49 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/20 13:08:22 by mvalk         ########   odam.nl         */
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
		sort_stack(a, b, stack_size, 0.65);
	else
		sort_stack(a, b, stack_size, 0.8);
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

void	proxy_move(t_stack **a, t_stack *move_num, int stack)
{
	int		mid_point;

	set_index(a);
	mid_point = ft_stack_size(*a) / 2;
	if (mid_point > move_num->index)
	{
		while ((*a)->true_index != move_num->true_index)
		{
			if (stack == 'a')
				ft_ra(a);
			else
				ft_rb(a);
		}
	}
	else
	{
		while ((*a)->true_index != move_num->true_index)
		{
			if (stack == 'a')
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
		proxy_move(b, is_biggest(b), 'b');
		ft_pa(a, b);
	}
}
