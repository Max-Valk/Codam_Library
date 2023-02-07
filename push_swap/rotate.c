/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 16:50:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/25 15:22:22 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

void	ft_rotate(stack **head)
{
	stack	*last;
	stack	*head_next;

	head_next = (*head)->next;
	if (head_next)
	{
		last = ft_stacklast(*head);
		last->next = (*head);
		(*head)->next = NULL;
		(*head)->prev = last;
		head_next->prev = NULL;
		*head = head_next;
	}
}

void	ft_ra(stack	**a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(stack **a, stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
