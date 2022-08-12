/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:08:22 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/10 01:02:05 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function sequentially allocates enough space for 'count'
 * number of objects that are 'size' bytes of memory each. It then returns a 
 * pointer to the newly allocated memory. This memory is filled with byes of
 * value zero.
 *
 * So we set up a pointer 'ptr' to our allocated memory using malloc. If 
 * there's nothing passed to the function then we return NULL. Then while
 * our counter is less than (count * size) we increment through and set all
 * the elements of our allocated space to zero before returning sending the
 * pointer home.*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
