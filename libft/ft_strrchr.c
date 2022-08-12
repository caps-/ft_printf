/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:29:28 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/21 14:29:40 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strrchr() function locates the last occurence of c, converted to a
 * char, in the string pointed to by s. The null terminator is considered to be
 * part of the string, so if c is '\0' the function will try to locate it too.
 *
 * So we'll start with a quick while loop (statement?) here that just counts up
 * the number of characters in the string. Once that's done we go in to another
 * while loop, that starts at the end of the string and checks to see if the
 * search character is there. If it is, it returns a pointer to it that's been
 * converted to a normal char so it can point to whatever. If it doesn't find
 * c then it moves to the previous position and does it again, over and over
 * until it hits the start of the string. We have that same loop by itself
 * after the while loop too just in case the string is only one character (in
 * the 0th position). Return 0 at the end because success.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
