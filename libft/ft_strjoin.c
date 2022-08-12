/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:59:02 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/06 17:54:38 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new string, which is the result of 
 * the concatenation of ’s1’ and ’s2’. Returns the new string, or NULL if the
 * allocation fails.
 *
 * I fucking hate the word 'concatonate', so just for my own sake, a quick
 * reminder that concatonate basically means to join two character strings
 * end to end. In other words, it makes compound words.
 *
 * I probably didn't need to use the two len variables here but it made the
 * malloc use look nicer to me, so that's what I did. So we start out by using
 * our ft_strlen() function to get the lengths of the two passed strings and
 * store them in the len variables, which then get used with malloc to allocate
 * the memory for our str. Plus one on the end to make room for the null
 * terminator. If the allocation fails we return null. The first while loop here
 * just copies the first passed string over to our own str, stopping once it
 * hits the null terminator. Then the second while loop starts, using j to both
 * move through s2 and to keep moving through our str, carrying on from where
 * the first while loop left off. Other than that it basically works the same as
 * the first one. Finally we stick our null terminator at the end and return
 * our new string.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*str;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
