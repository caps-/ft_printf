/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:35:06 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/07 13:50:39 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Locates the first occurence of c (converted to a char) in the string pointed
 * to by s. The terminating null character is considered to pe part of the
 * string, so if c is '\0' the function will locate it. 
 *
 * The function returns a pointer to the located character, or NULL if it does
 * not appear in the stirng.
 *
 * Nothing too crazy here. We're setting up a little pointer to move through
 * the string here. We'll jump in to a while loop that will move through the
 * string until it encounters the character we're looking for. If it hits a
 * null terminator it'll retun null, otherwise it will return the pointer to
 * the position where the c character appears.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p != (char)c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}
