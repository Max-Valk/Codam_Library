/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 11:54:49 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/27 15:17:23 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_list = ft_lstlast(*lst);
	last_list->next = new;
}

// int	main(void)
// {
// 	t_list	*test_node = ft_lstnew("It doesn't work");
// 	t_list	*start = ft_lstnew("it maybe works?");
// 	t_list	*node1 = ft_lstnew("It doesn't work");
// 	t_list	*node2 = ft_lstnew("It doesn't work");
// 	t_list	*new_node = ft_lstnew("It works");
// 	start->next = node1;
// 	node1->next = node2;
// 	node2->next = NULL;

// 	ft_lstadd_back(&start, new_node);
// 	test_node = ft_lstlast(start);
// 	// int c = ft_lstsize(start);
// 	printf("Result:\t%s!", test_node->content);
// 	return (0);
// }