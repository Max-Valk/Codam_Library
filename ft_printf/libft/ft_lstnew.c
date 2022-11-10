/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 14:45:56 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:57:39 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	return (new_lst);
}
