/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:09:30 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/26 16:23:40 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the element 'new' at the end of the list.
 *
 * The first paramater is the address of a pointer to the first link of a list.
 * Second is the address of a pointer to the element to be added to the list.
 *
 * First thing we do is check to see if both params are actually being used. If 
 * they aren't we just return nothing. Then we check to see if 'lst' is empty.
 * If that's the case, it points to the 'new' element and adds it to the list.
 * 
 * Next we use our function ft_lstlast() to get the pointer to the last element
 * of '*lst' and store it in 'element'. Finally the 'element' pointer to the
 * 'next' element (->, or arrow operator) is set to 'new' so we can add it to 
 * the list. Remember that 'next' is defined in our libft.h file and is part of
 * the t_list struct.*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		element = ft_lstlast(*lst);
		element->next = new;
	}
}
