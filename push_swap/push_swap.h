/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:15:41 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/16 14:42:54 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct stack
{
	int data;
	struct stack *prev;
	struct stack *next;
}				stack;

stack	*ft_stack_new(int num);
stack	*ft_stacklast(stack *node);
void	 ft_stackadd_back(stack **front, stack *new);
void 	ft_stackadd_front(stack **front, stack *new);
void	ft_delstack(stack *node);
int		ft_stack_size(stack *start);

void	ft_sa(stack **stack_a);
void	ft_sb(stack **stack_b);
void	ft_ss(stack **stack_a, stack **stack_b);

void	ft_rotate(stack **head);
void	ft_reverse_rotate(stack **head);

void	ft_pa(stack **a, stack **b);
void	ft_pb(stack **a, stack **b);

void	ft_ra(stack	**a);
void	ft_rb(stack **b);
void	ft_rr(stack **a, stack **b);

void	ft_rra(stack **a);
void	ft_rrb(stack **b);
void	ft_rrr(stack **a, stack **b);


#endif