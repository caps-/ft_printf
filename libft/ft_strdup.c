/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:30:55 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/06 17:25:36 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strdup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it. If insufficient memory is
 * unavaliable it returns NULL.
 * 
 * Simple ting dis. We allocate the memory in our str variable with the help of
 * our ft_strlen() function we also write, and add one on the end so we can put
 * a null terminator on the end once it's done. If the allocation fails we
 * return null. Then we copy over each position in the original string to the
 * duplication and move on to the next position and keep doing it until we hit
 * the end. Then we just stick a null terminator in the final spot and return
 * the freshly duplicated string.*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
