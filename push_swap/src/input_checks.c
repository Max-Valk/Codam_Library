/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:09:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/12 18:01:53 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

int	dupe_check(char **param)
{
	int	to_comp;
	int	j;
	int	i;

	i = 0;
	while (param[i])
	{
		j = i + 1;
		to_comp = ft_atoi(param[i]);
		while (param[j])
		{
			if (to_comp == ft_atoi(param[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input_type(char **param)
{
	int	j;
	int	i;

	i = 0;
	while (param[i] != NULL)
	{
		j = 0;
		if (param[i][0] == '-')
			j++;
		if (param[i][j] == '\0')
			return (1);
		while (param[i][j])
		{
			if (!ft_isdigit(param[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_list(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free (tmp);
		tmp = next;
	}
	*head = NULL;
}

t_stack	*ft_make_list(char **input)
{
	int		i;
	long	data;
	t_stack	*head;
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	head = NULL;
	i = 0;
	while (input[i] != NULL)
	{
		data = ft_atoi(input[i]);
		if (data > INT_MAX || data < INT_MIN)
			return (free_list(&head), NULL);
		tmp_stack = ft_stack_new(data);
		if (!tmp_stack)
			return (free_list(&head), NULL);
		ft_stackadd_back(&head, tmp_stack);
		i++;
	}
	return (head);
}
