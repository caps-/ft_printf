/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:16:26 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/27 16:38:53 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function takes an element as a paramater and then frees the meory of
 * the elements content using 'del'. Whatever's in 'next' must not be freed.
 *
 * Pretty simple code tbh. Null check, then the functiont del is run on the 
 * content of the element 'lst' and then the memory is freed up.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
