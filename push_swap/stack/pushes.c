/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 13:36:30 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/19 16:46:03 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_push(t_stack **stack_dst, t_stack **stack_src)
{
	t_stack	*src_next;

	if (*stack_src == NULL)
		return ;
	src_next = ((*stack_src)->next);
	ft_stackadd_front(stack_dst, *stack_src);
	if (src_next != NULL)
		src_next->prev = NULL;
	*stack_src = src_next;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_printf("pb\n");
}
