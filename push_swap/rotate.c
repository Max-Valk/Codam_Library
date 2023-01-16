/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 16:50:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/16 13:35:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

void	ft_rotate(stack **head)
{
	stack	*last;
	stack	*head_next;

	head_next = (*head)->next;
	last = ft_stacklast(*head);
	last->next = (*head);
	(*head)->next = NULL;
	(*head)->prev = last;
	head_next->prev = NULL;
	*head = head_next;
}

void	ft_ra(stack	**a)
{
	ft_rotate(a);
}

void	ft_rb(stack **b)
{
	ft_rotate(b);
}

void	ft_rr(stack **a, stack **b)
{
	ft_ra(a);
	ft_rb(b);
}
