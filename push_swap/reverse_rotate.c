/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 13:40:40 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/08 15:35:04 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **head)
{
	t_stack	*stack_last;
	t_stack	*tmp;
	t_stack	*last_prev;

	tmp = *head;
	stack_last = ft_stacklast(tmp);
	last_prev = stack_last->prev;
	tmp->prev = stack_last;
	stack_last->prev = NULL;
	stack_last->next = tmp;
	if (last_prev)
		last_prev->next = NULL;
	*head = stack_last;
}

void	ft_rra(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack	**b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
