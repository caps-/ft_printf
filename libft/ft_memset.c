/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:49:25 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/01 15:13:03 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Write len bytes of value c (converted to an unsigned char) to the string b.*/
/* 
 * Another pretty basic one. We set up a pointer to the string and a counter.
 * Then we just get a likkle while loop going and copy c over to b over
 * and over until our counter hits len, then we return b.*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
