/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:34:05 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/04 15:34:47 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_memcmp() function compares the byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * The ft_memcmp() function returns zero if the two strings are identical,
 * otherwise returns the difference between the first two differing bytes which
 * are treated as unsigned char values, so that '\200' is greater than '\0' for
 * example. Zero length strings are always identical.
 *
 * In other words, what it does is compare two strings against each other and
 * return an integer value depending on the relationship between the two
 * strings, <0 for the first byte that doesn't match has a lower value in s1 
 * than in s2, 0 if they're equal, and >0 if the first byte that doesn't match
 * has a higher value in s1 than it does in s2.
 *
 * We set up two pointers to s1 and s2 and cast them as unsigned chars. Then
 * we start incrementing our counter as long as the two strings are the same
 * and i is less than the size we've passed to n. Then as long as i is less
 * than n we subtract the two matching values and return that value which will
 * give us our result. Otherwise we just return 0.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	i = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	while (s1_ptr[i] == s2_ptr[i] && i < n)
	{
		i++;
	}
	if (i < n)
	{
		return (s1_ptr[i] - s2_ptr[i]);
	}
	return (0);
}
