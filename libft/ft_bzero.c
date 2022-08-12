/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:57:02 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/10 00:40:42 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_bzero() function erases the data in the 'n' bytes of the memory,  
 * starting at the location pointed to by 's', by writing zeroes (bytes
 * containing '\0' to that area.
 * 
 * We use our ft_memset() function to literally do what the description says.
 *
 * That's it.
 *
 * That's the function.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
