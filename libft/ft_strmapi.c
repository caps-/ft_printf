/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:15:32 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/01 14:23:22 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The description for this one is fucked. Basically ft_strmapi applies the 
 * function 'f' to each character of the string 's', then creates a new string
 * using malloc that is made of the result of successive applications of 'f'.
 * So I guess f could be any function you want really, like you could use
 * ft_toupper or something to go through the string, or make one that changes
 * every 'e' character to 'E' or something like that. Pretty cool!
 *
 * -
 * Anyway, we use our ft_strlen() function to figure out the length of the
 * passed string and store that value in length,t hen we create a new result
 * string using malloc. If the malloc fails we return null. Next we start
 * applying f to each element of our new string until we hit the end, then
 * stick a null terminator on the end before returning the final result
 * -
 * So first we check to make sure a string has been passed to the function, if
 * not we return NULL. Next we set up our string we're gunna return using
 * malloc and our ft_strlen() function to allocate the right amount of memory
 * for it. If the allocation fails we also return NULL. Then we go in to a while
 * loop that runs until we hit the nul terminator. We just increment through
 * the string we set up earlier and run the function on each character. Pretty
 * simple really. Once we hit the null terminator we exit the loop, add our own
 * null terminator in what is now the last position in the string and return the
 * new, final string.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
