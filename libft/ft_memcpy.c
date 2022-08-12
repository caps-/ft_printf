/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:27 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/20 14:04:25 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_memcpy() function copies the values of n bytes from the location
 * pointed to by source to the block of memory pointed to by dest.
 *
 * Pretty simple copy code here, we just make each position in dst the same as
 * the one in src and increment along before returning dst. Easy peasy.*/

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
