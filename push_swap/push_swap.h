/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:15:41 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/24 17:21:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct stack
{
	int data;
	int	index;
	int	true_index;
	struct stack *prev;
	struct stack *next;
}				stack;

//temp functions
void	print_list(stack **head);
//

stack	*ft_stack_new(int num);
stack	*ft_stacklast(stack *node);
void	 ft_stackadd_back(stack **front, stack *new);
void 	ft_stackadd_front(stack **front, stack *new);
void	ft_delstack(stack *node);
int		ft_stack_size(stack **start);

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

stack	*ft_make_list(stack **head, char **argv, int arg_type);
int		check_input_type(char **argv, int arg_type);
int		check_input_value(stack **head);
void	error_exit(void);

void	sort_2(stack **a);
int		sort_size(stack **a, stack **b);
int		is_sorted(stack **a);
stack	*is_lowest(stack **a);

void	bubble_sort(stack **a, stack **b);
int		ft_reverse_stack_size(stack *start);
int		rotate_direction(stack **start);

void	sort_3(stack **a);
void	sort_4(stack **a, stack **b);
void	sort_5(stack **a, stack **b);

void	set_index(stack **a);
void	sort_10(stack **a, stack **b);

#endif