/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 16:50:56 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 15:35:04 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdint.h>

static void	ft_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*head_next;

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

void	ft_ra(t_stack	**a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
