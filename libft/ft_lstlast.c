/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:29:45 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/31 10:42:14 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the last node of the list.
 *
 * Null check, then a likkle loop where we point 'lst' to the next element 
 * in our t_list. This just keeps looping until it hit's the last one in there.
 * Then we just return 'lst'. */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
