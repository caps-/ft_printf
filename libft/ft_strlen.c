/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:11 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/11 02:08:47 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strlen() function computes the length of the string s. Das it. The
 * function then returns the number of characters that preceed the terminating
 * NULL character.
 *
 * Preeeeetty basic, just a super simple while loop that counts through s until
 * it hits the null terminator and returns the result.*/

#include "libft.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
