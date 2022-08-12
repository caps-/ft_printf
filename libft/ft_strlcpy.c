/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:18:03 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/07 13:34:59 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function copies the null terminated string from src to dst, up to 
 * dstsize characters, then returns the total length of the string it tried to
 * create. To prevent writing outsize the bounds of the array the function
 * takes the full size of the destination string as a size paramater.
 *
 * First up we check to see if anything was actually passed as a source, if not
 * we return 0. Then if our dstsize is zero we just use our Ft_strlen() function
 * to return the length of the source string. Next is a likkle while loop. So
 * while i is less than dstsize - 1 (so we don't include the null terminator) we
 * copy over src to dst until we hit tne end of the src string. Then if our
 * dstsize isn't zero (which it honestly shouldn't be) then we add our own null
 * terminator to the end, then use ft_strlen to return the length of the string
 * it created.*/

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
