/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 15:41:41 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/05 15:29:50 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*stack_to_array(t_stack **a)
{
	int		*num_array;
	int		i;
	t_stack	*tmp;

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

static void	swap_int(int *num_array, int i, int j)
{
	int	tmp;

	tmp = num_array[i];
	num_array[i] = num_array[j];
	num_array[j] = tmp;
}

void	quicksort(int *num_array, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

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
				swap_int(num_array, i, j);
		}
		swap_int(num_array, pivot, j);
		quicksort(num_array, first, j - 1);
		quicksort(num_array, j + 1, last);
	}
}
