/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:05:20 by pwhittin          #+#    #+#             */
/*   Updated: 2022/04/05 12:14:01 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Likkle function to print characters, including a bit of formatting.
 *
 * First up, ye olde ft_putchar().*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* Pretty simple dis. So as long as i is less than the minimum width specified,
 * it'll add spaces and increment up until it reaches said width. Once that's
 * done it goes ahead and puts whatever actual character was passed. Similar
 * deal with the offset, just doesn't bother putting the character after.*/

int	ft_printchar(char c, t_spec spec)
{
	int	i;

	i = 0;
	while (i + 1 < spec.min_width)
		i += ft_putchar(' ');
	i += ft_putchar(c);
	while (i < spec.offset)
		i += ft_putchar(' ');
	return (i);
}
