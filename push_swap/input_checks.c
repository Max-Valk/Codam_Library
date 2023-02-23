/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:09:07 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/14 16:32:34 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	dupe_check(char **argv)
{
	int	to_comp;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		to_comp = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (to_comp == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input_type(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (0);
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	*free_list(t_stack **head)
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
	return (NULL);
}

t_stack	*ft_make_list(t_stack **head, char **argv)
{
	int		i;
	long	data;
	t_stack	*tmp_stack;

	tmp_stack = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		data = ft_atoi(argv[i]);
		if (data > INT_MAX || data < INT_MIN)
			return (free_list(head));
		tmp_stack = ft_stack_new(data);
		if (!tmp_stack)
			return (free_list(head));
		ft_stackadd_back(head, tmp_stack);
		i++;
	}
	return (*head);
}
