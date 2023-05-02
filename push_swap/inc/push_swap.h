/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 14:15:41 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/20 13:31:42 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct t_stack
{
	int				data;
	int				index;
	int				true_index;
	struct t_stack	*prev;
	struct t_stack	*next;
}				t_stack;

int		push_swap(char **input);

/*stack management*/

t_stack	*ft_stacklast(t_stack *node);
t_stack	*is_lowest(t_stack **a);
void	ft_stackadd_front(t_stack **front, t_stack *new);
int		ft_stack_size(t_stack *start);

/*stack moves*/

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

/*list init*/

t_stack	*ft_make_list(char **argv);
t_stack	*ft_stack_new(int num);
void	ft_stackadd_back(t_stack **front, t_stack *new);

/*input checks*/

int		check_input_type(char **input);
int		dupe_check(char **input);
int		is_sorted(t_stack **a);

/*free and error handling*/

void	free_list(t_stack **head);
void	free_input(char **input);
int		error_exit(void);

/*sort functions*/

void	sort_small(t_stack **a, t_stack **b, int stack_size);
void	sort_big(t_stack **a, t_stack **b, int stack_size);
void	sort_stack(t_stack **a, t_stack **b, int stack_size, double factor);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);

/*pre sort utils*/

int		*stack_to_array(t_stack **a);
void	quicksort(int *num_array, int first, int last);
void	set_index(t_stack **a);
void	set_true_index(t_stack **a, int *sorted_array);

/*stack sort utils*/

int		new_pivot(int live_stack_size, int stack_size, double factor);
void	num_push(int pivot_num, int prev_pivot, t_stack **a, t_stack **b);
t_stack	*is_biggest(t_stack **a);
void	proxy_move(t_stack **a, t_stack *move_num, int stack_a);
void	push_b_back(t_stack **a, t_stack **b);

#endif
