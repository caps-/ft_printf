/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:15:55 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/15 10:45:12 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Another one where the man page just sucks. We're comparing two null
 * terminated strings, s1 and s2 up to n characters, so you'd use it something
 * like ft_strncmp(string1, string2, 10) to compare the two strings up to 10
 * characters. It returns a value less than, greater than or equal to zero
 * depending on whether the stopping character in s1 is less than, greater than 
 * or equal to the one in s2.
 *
 * First we check that n actually has a value, if it doesn't we return 0. Then
 * we go in to a while loop, for as long as s1 and s2 have something and our
 * counter i hasn't hit the size passed to the function. We have an if statement
 * in there that tells the program that if whatever is in the ith position in
 * both strings don't match then it will convert them to unsigned chars and then
 * substract the character in s2[i] from s1[i]. That will give us either a
 * positive number, a negative number or zero which is what the program will
 * return. If they match then the counter increments and we check the next
 * positions in the strings. If we get to the end of the loop and they still
 * match we return 0. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
