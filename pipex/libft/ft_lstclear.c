/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 13:17:20 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 14:52:20 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_lst;
	t_list	*tmp_lst;

	del_lst = *lst;
	while (del_lst)
	{
		tmp_lst = del_lst->next;
		ft_lstdelone(del_lst, del);
		del_lst = tmp_lst;
	}
	*lst = NULL;
}
