/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_100.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 13:48:51 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/07 13:32:08 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	*stack_to_array(stack **a)
{
	int	*num_array;
	int	i;
	stack	*tmp;

	tmp = *a;
	i = 0;
	num_array = (int *)malloc(ft_stack_size(*a) + 1);
	if (!num_array)
		return (NULL);
	while (tmp != NULL)
	{
		num_array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	num_array[i] = '\0';
	return (num_array);
}

void	quicksort(int *num_array, int first, int last)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (num_array[i] <= num_array[pivot] && i < last)
				i++;
			while (num_array[j] > num_array[pivot])
				j--;
			if (i < j)
			{
				tmp = num_array[i];
				num_array[i] = num_array[j];
				num_array[j] = tmp;
			}
		}
		tmp=num_array[pivot];
		num_array[pivot] = num_array[j];
		num_array[j] = tmp;
		quicksort(num_array, first, j - 1);
		quicksort(num_array, j + 1, last);
	}
}

void	set_true_index(stack **a, int *sorted_array)
{
	stack	*tmp;
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

void	proxy_move(stack **a, stack *move_num, int stack_a)
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

void	push_b_back(stack **a, stack **b)
{
	while (*b)
	{
		proxy_move(b, is_biggest(b), 0);
		ft_pa(a, b);
	}
}

void	sort_last_quart(stack **a, stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		proxy_move(a, is_lowest(a), 1);
		ft_pb(a, b);
	}
	sort_3(a);
}

int	calculate_pivot_100(int live_stack_size, int stack_size)
{
	int	pivot_num;
	
	if (live_stack_size >= (stack_size * 0.75))
		pivot_num = (stack_size / 4) + 1;
	else if (live_stack_size >= stack_size / 2)
		pivot_num = (stack_size / 2) + 1;
	else
		pivot_num = (stack_size * 0.75) + 1;
	return (pivot_num);	
}

int	sort_100(stack **a, stack **b, int stack_size)
{
	int		pivot_num;
	int		live_stack_size;

	live_stack_size = stack_size;
	while (live_stack_size >= stack_size / 4)
	{
		pivot_num = calculate_pivot_100(live_stack_size, stack_size);
		while (live_stack_size >= stack_size - pivot_num)
		{
			if ((*a)->true_index <= pivot_num)
			{
				proxy_move(a, *a, 1);
				ft_pb(a, b);
				if ((*b) && (*b)->next)
					if ((*b)->true_index > pivot_num - (stack_size / 8))
						ft_rb(b);
				live_stack_size = ft_stack_size(*a);
			}
			else
				ft_ra(a);
		}
	}
	sort_last_quart(a, b);
	push_b_back(a, b);
	return (1);
}
