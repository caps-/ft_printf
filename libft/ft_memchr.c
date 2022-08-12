/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:32 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/04 14:17:17 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Locates the first occurence of c (converted to an unsigned char) in string
 * s. It returns a pointer to the byte located or NULL if it doesn't.
 *
 * So from what I can tell this function, as well as the OG, actually finds
 * the first occurence of c in the string and then prints the string STARTING
 * from that character. So .. I dunno. That's what this does.
 *
 * So we set up a pointer to the input string then start looking at said
 * string from the start. If whatever's in the current spot in the string is
 * the character we passed to the functino then we we return the string from
 * that spot, otherwise we increment through the string and keep the counter
 * going until we hit the end.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char) c;
	while (i < n)
	{
		if (*str == ch)
		{
			return (str);
		}
	str++;
	i++;
	}
	return (NULL);
}
