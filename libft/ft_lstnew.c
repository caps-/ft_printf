/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:00:36 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/31 11:14:18 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc) and returns a new node. The member variable 'content'
 * is initialized with the value of the paramanter 'content'. The variable
 * 'next' is initialized to NULL. 
 *
 * We set up our viarable 'element', and then use malloc to allocate the space
 * for our new node then run a null check to make sure there's actually stuff
 * in the element. Then we point element to content in our list and assign it
 * with whatever we passed to the main function. Then we point element to next
 * and set it to NULL before finally returning the new node/element. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
