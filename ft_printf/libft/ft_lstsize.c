/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 16:06:52 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:57:31 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		lst_count;
	t_list	*ptr;

	lst_count = 0;
	ptr = lst;
	while (ptr)
	{
		lst_count++;
		ptr = ptr->next;
	}
	return (lst_count);
}
