/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 13:40:40 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/19 13:55:26 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(stack **head)
{
	stack	*stack_last;
	stack	*last_prev;

	stack_last = ft_stacklast(*head);
	last_prev = stack_last->prev;
	(*head)->prev = stack_last;
	stack_last->prev = NULL;
	stack_last->next = *head;
	if (last_prev)
		last_prev->next = NULL;
	*head = stack_last;
}

void	ft_rra(stack **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(stack	**b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(stack **a, stack **b)
{
	ft_rra(a);
	ft_rrb(b);
	ft_printf("rrr\n");
}
