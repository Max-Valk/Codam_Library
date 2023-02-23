/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:15:41 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/14 13:56:34 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct t_stack
{
	int				data;
	int				index;
	int				true_index;
	struct t_stack	*prev;
	struct t_stack	*next;
}				t_stack;

//temp functions
// void	print_list(stack **head);
//

t_stack	*ft_stack_new(int num);
t_stack	*ft_stacklast(t_stack *node);
void	ft_stackadd_back(t_stack **front, t_stack *new);
void	ft_stackadd_front(t_stack **front, t_stack *new);
void	ft_delstack(t_stack *node);
int		ft_stack_size(t_stack *start);

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

void	ft_ra(t_stack	**a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

t_stack	*ft_make_list(t_stack **head, char **argv);
int		check_input_type(char **argv, int argc);
int		duplicate_check(t_stack **head);
int		error_exit(void);

void	sort_2(t_stack **a);
int		sort_small(t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
t_stack	*is_lowest(t_stack **a);

void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

int		sort_big(t_stack **a, t_stack **b, int stack_size);
void	set_index(t_stack **a);
void	sort_20(t_stack **a, t_stack **b);

int		*stack_to_array(t_stack **a);
void	quicksort(int *num_array, int first, int last);
void	set_true_index(t_stack **a, int *sorted_array);
t_stack	*is_biggest(t_stack **a);

int		sort_100(t_stack **a, t_stack **b, int stack_size);
int		calculate_pivot_100(int live_stack_size, int stack_size);
void	sort_last_quart(t_stack **a, t_stack **b);
void	push_b_back(t_stack **a, t_stack **b);
void	proxy_move(t_stack **a, t_stack *move_num, int stack_a);

int		sort_500(t_stack **a, t_stack **b, int stack_size);
int		dupe_check(char **argv);

#endif
