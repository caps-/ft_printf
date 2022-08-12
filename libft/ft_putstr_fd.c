/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:12:51 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/04 16:52:38 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string 's' to the given file descriptor.
 *
 * Null check, then we just write the string and use our ft_strlen() function
 * to get us the number we need for the write function. Boom!*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
