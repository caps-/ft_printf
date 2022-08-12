/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:17:41 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/07 14:36:34 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Printing strings! Aw yeah! ALways good to start with the classics, so let's
 * implement ft_putstr() here first.*/

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

/* This returns the length of the string, including precision. Commenting all
 * of these is long so I'm going to hope that the code here is pretty self
 * explanitory. */

static int	putstrsize(char *str, int strsize)
{
	int	i;

	if (strsize == -1)
		return (ft_putstr(str));
	i = 0;
	while (str[i] && i < strsize)
		write(1, &str[i++], 1);
	return (i);
}

/* Comment me later, it's messy (to my eyes anyway) but it works and not too
 * hard to follow I don't think. */

/* We init our counter i to zero first, then check to see if there's even a
 * string there. If there's nothing, we set our len variable to 6 to give us
 * room for a printed output of "(null)". Easy. Next we take care of our
 * format specifiers and then if there's no string there we actually print out
 * the "(null)" thing I mentioned before. If there actually IS a string there
 * we use the putstrsize() function to both print out the string as well as
 * send back a character count. Then we handle whatever offset we have before
 * finally returning a total character count which is sent back to the main
 * ft_printf() function. */

int	ft_printstr(char *str, t_spec spec)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (i + len < spec.min_width)
		i += ft_putchar(' ');
	if (!spec.dot)
		spec.precision = -1;
	if (!str)
		i += putstrsize("(null)", spec.precision);
	else
		i += putstrsize(str, spec.precision);
	while (i < spec.offset)
		i += ft_putchar(' ');
	return (i);
}
