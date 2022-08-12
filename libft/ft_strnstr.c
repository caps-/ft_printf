/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:43:05 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/15 10:52:40 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strnstr() function locates the first occurence of the null terimnated
 * string needle in the string haystack, searching up to len characters. At
 * least that's what the OG function says, for brevity's sake we're going to 
 * rename them s1 and s2 in our implementation. Characters that appear after 
 * '\0' aren't searched. If s2 is an empty string, s1 is returned. If s2 does 
 * not occur anywhere in s1 it returns NULL, otherwise a pointer to the first 
 * character of the first occurence of s2 is returned.
 *
 * We're doing this whole thing inside a while loop that runs until we hit the
 * length we're searching and s1 hasn't hit the null terminator yet. Inside this
 * loop we have another while loop that looks like it has a lot going on but
 * actually isn't too bad. We basically just start comparing the two strings 
 * as long as we don't hit our length value and s2 hasn't reached the null
 * terminator. Because we're using i + j values for s1 and only j for s2, when
 * we increment j we're keeping s1 where it is and checking the next thing in
 * s2. Then enother if statement saying if/when we hit the end of s2 we return
 * a pinter to the place in s1 where the match occurs, otherwise we go back to 
 * the start of the loop and do it all again, this time at the second position 
 * in s1. If there's no match then the whole thing returns NULL and we're all 
 * done.*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		j = 0;
		while (i + j < len && s1[i + j] == s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
