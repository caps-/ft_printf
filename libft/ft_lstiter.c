/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:34:25 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/21 15:12:35 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list 'lst' and applies the function 'f' to the content of
 * each element.
 * 
 * Another pretty simple one. Null check like always, then we run the function
 * 'f' on the content of the element 'lst', then iterate by making lst point to
 * the next element. Noice.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
