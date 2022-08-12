/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:48:28 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/20 14:30:39 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds element 'new' at the beginning of the list. The first paramater is the
 * address of a pointer to the first element of the a list. The second paramater
 * is the address of a pointer to the new element to be added to the list.
 *
 * After a quick null check wet take the new element and point it to the 'next'
 * element in the main list. Then we set the pointer of lst to new which sets
 * it to the start of our linked list.*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
