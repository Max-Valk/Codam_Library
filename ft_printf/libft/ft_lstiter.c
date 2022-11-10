/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 15:17:47 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/27 15:29:23 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*mod_lst;

	mod_lst = lst;
	if (!lst)
		return ;
	while (mod_lst)
	{
		f(mod_lst->content);
		mod_lst = mod_lst->next;
	}
}
