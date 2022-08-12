/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:42:37 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/01 15:48:39 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a substringfrom the string ’s’.The 
 * substring begins at index ’start’ and is of maximum size ’len’.
 *
 * That's what the subject says. I think this is a terrible name and a really
 * unclear description. Basically this thing just takes a string, copies it
 * from 'start' characters in up until 'len' characters after that and  then 
 * returns the result as a new string. So like ft_substr("bumboclaat", 5, 3)
 * would return "cla".
 * 
 * We'll use three variables here; a counter i, a pointer to the string we want
 * to return called newstr, and s_len which will store the length of the string
 * we passed to the function. We do a null check on s, then get in to the meat
 * of the function. We'll use our own ft_strlen() function from the library to
 * get the length of the passed string and then assign it s_len. If the value
 * for len that we passed to the function is greater than the length of the
 * string then we set the length of len to s_len to keep it from going out of
 * bounds so to speak. Then we'll set up our new string by using malloc and
 * len + 1 to make room for the terminator at the end. If the allocation fails
 * for some reason we'll return NULL. Then we go in to a while loop that copies
 * over the data from our passed string to the new substring. God I still find
 * this kinda thing so awkward to describe, but like .. it starts from whatever
 * position we've told it to start at and increments/copies along until it hits
 * the length we've told it to copy to and the start position is less than the
 * length of the whole string. I dunno the operation itself is simple I guess 
 * but I just find it hard to describe clearly. Check my code again in a year 
 * and we'll see if I get any better lol.*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	newstr = malloc(sizeof(char) * len + 1);
	if (!newstr)
		return (NULL);
	while (s[start + i] && i < len && start < s_len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
