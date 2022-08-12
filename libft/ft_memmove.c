/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:09:27 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/04 16:26:54 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies len bytes from the string src to the string dst, with the two strings
 * allowed to overlap. It doesn't actually check for a null terminator either,
 * it copies exactly len bytes.
 *
 * Basically we check to see if destination value is greater than the source,
 * and then decrement (still hate that word) back so that it just kinda
 * sticks source on the end. Otherwise if it's the other way round and the 
 * source is bigger than the destination we just copy the source over using
 * our ft_memcpy() function. Finally return the dst with the newly copied
 * shit in it.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else if (dest < source)
		ft_memcpy(dst, src, len);
	return (dst);
}
