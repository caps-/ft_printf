/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:08:43 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/07 13:51:04 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocated (with malloc(3)) and returns a copy of 's1' with the characters
 * specified in 'set' removed from the start and the end of the string.
 *
 * Returnes the trimmed string, NULL if allocation fails.
 *
 * This one has given me so much grief lol. Let's break it down.
 *
 * First up we're making a function to check that the character we want to trim
 * is there. We just increment along through the string checking each position
 * for c, and if we find it returning 1. This will help up laster on in the
 * proper ft_strtrim() function.*/

#include "libft.h"

int	search_string(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

/* Quick null check, then on to the main event. We're setting the value of our
 * start counter i and the value of our start variable to 0. Then we use the
 * ft_strlen() function to get the length of the string which is also the
 * end position we're going to count back from. Our first while loop checks
 * the first position in our string and runs our search function on the set,
 * then increments on to the next position until ft_search() returns 1. The
 * second while loop basically does the same back moves backwards from the
 * last position. Now we have those positions stored we can use malloc to
 * allocate the space for the string containig our result, adding an extra spot
 * for our null terminator. Taking the last position and subtracting the value
 * of the first position gives us the right size btw. If the result is null we
 * return null. Then we got our final loop which will copy over copy over our
 * trimmed string to the result string starting from the first position in s1
 * after the character we've trimmed until we get to the last position before
 * the cut at the end. Finally we add a null terminator and return the final
 * trimmed string. */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (s1 == 0)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && search_string(s1[start], set))
		start++;
	while (end > start && search_string(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
