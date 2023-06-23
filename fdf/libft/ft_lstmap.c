/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 15:30:39 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/17 16:08:15 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_f_list;
	t_list	*tmp_lst;

	if (!lst || !*f || !*del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp_f_list = f(lst->content);
		tmp_lst = ft_lstnew(tmp_f_list);
		if (tmp_lst == NULL)
		{
			del(tmp_f_list);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst->next;
	}
	return (new_lst);
}

// int	main(void)
// {
// 	char *a = "123";
// 	char *b = "567";
// 	char *c = "999";
// 	t_list	*start = ft_lstnew(a);
// 	t_list	*node1 = ft_lstnew(b);
// 	t_list	*node2 = ft_lstnew(c);
// 	// t_list	*test_node = ft_lstnew("It doesn't work");
// 	start->next = node1;
// 	node1->next = node2;
// 	node2->next = NULL;

// 	// test_node = ft_lstlast(start);
// 	// int c = ft_lstsize(start);
// 	ft_lstmap(start, (void *)ft_isascii, (void *)ft_bzero);
// 	printf("List 1: %s\n", start->content);
// 	printf("list 2: %s\n", node1->content);
// 	printf("list 3: %s\n", node2->content);
// 	system("leaks -q a.out");
// 	return (0);
// }
