/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:26:08 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/07 12:48:09 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strlcat() function appends string src to the end of dst, using size
 * to determine how many characters to append. It will then null terminate,
 * unless size is 0 or the original dst string was longer than size.
 *
 * I've set up two variables for the function here just to make things a little
 * neater. We'll use our ft_strlen() funciton to get the length/size of the
 * strings and keep that value in their respective variables. Then a likkle if
 * statement that just says if size is less than the size of the dst string we
 * return size + s_len. Then if size is greater than size + d_len +1 we go in
 * to our little while loop. This guy says that as long as the dst string plus
 * i lis less than size - 1 we copy over src in to dst untill we hit the null
 * terminator. Once we're out of that loop we assign a zero value to the end of
 * our string and return the two strings joined together.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size < d_len + 1)
		return (size + s_len);
	if (size > d_len + 1)
	{
		while (src[i] != '\0' && d_len + i < size - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
