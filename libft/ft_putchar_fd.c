/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:13:31 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/04 16:36:01 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the character 'c' to the given file descriptor.
 *
 * Preeeety siple, just ye olde ft_putchar() with extra bits.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
