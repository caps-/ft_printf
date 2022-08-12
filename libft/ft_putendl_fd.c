/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:13:17 by pwhittin          #+#    #+#             */
/*   Updated: 2022/03/01 13:11:28 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string 's' to the given file descriptor followed by a newline.
 * 
 * Again, pretty simple, as far as I can tell it's literally just ft_putstr_fd()
 * with a newline after it. Not much to tell you here, using our ft_strlen()
 * function to tell write how many characters to do.*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
