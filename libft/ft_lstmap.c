/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:37:16 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/11 01:30:15 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list 'lst' and applies the function 'f' on the content of each
 * node. Creates a new list resulting from the successive applications of the
 * function 'f'. The 'del' function is used to delete the content of a node if
 * needed.
 *
 * This one did my head in for some reason. I hate you ft_lstmap.c.
 *
 * We start by setting up the first element of our new list and setting it to
 * NULL. Then we use our ft_lstnew() function to make a new element by running
 * whatever function we've passed on the content of said element. If there's
 * nothing there we use ft_lstclear() to remove whatever's in that particular
 * spot and then return zero. Then we use our ft_lstadd_back() function to add
 * the new element to the end of our first element before finally returning
 * the first element, which is now our new list.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*first_elem;

	first_elem = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&first_elem, del);
			return (0);
		}
		ft_lstadd_back(&first_elem, new_elem);
		lst = lst->next;
	}
	return (first_elem);
}
