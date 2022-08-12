/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:24:54 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/11 01:27:06 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given element and every successor of that element,
 * using the function 'del' and free(3). Fianlly, the pointer to the list must
 * be set to NULL.
 *
 * So first we do a quick null check and return nothing if either of the
 * params are empty. Then set up a pointer to the next element of '*lst' and
 * store that in 'temp'. Then we use the ft_lstdelone() function on '*lst' 
 * to, well, delete and free up that ellement. Then to keep the loop going we
 * point *lst back to 'lst->next' which we've saved in temp and it iterates 
 * along. */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
