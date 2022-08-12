/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:46:38 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/06 17:51:02 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Prints a negative long number. Pretty simple function here, just manually
 * adds a - character, then multiplies the number by -1 to make it negative.
 * */

static int	print_neg(long *l, int *len, t_spec spec)
{
	ft_putchar('-');
	(*l) *= -1;
	(*len)--;
	if (spec.dot)
		(*len)--;
	return (1);
}

/* This one figures out how many numbers the number to print uses. So 2 numbers
 * for 10, 3 numbers for 100 etc. Pretty simple.*/

static int	digitnbr(long l)
{
	int	i;

	i = 0;
	if (l == 0)
		return (1);
	if (l < 0)
		i++;
	while (l != 0)
	{
		l /= 10;
		i++;
	}
	return (i);
}

/* Figures out the values for the specifiers used.  */

static int	values(char *prefix, int *prec, t_spec *spec, long l)
{
	int	len;

	len = digitnbr(l);
	*prec = len;
	if (spec->precision > len)
		*prec = spec->precision;
	if (l < 0 && spec->zero_offset > len && spec->precision > len)
		(*prec)++;
	if (l < 0 && spec->dot && spec->precision < spec->zero_offset)
		len++;
	*prefix = '0';
	if (spec->zero && spec->dot && spec->zero_offset > spec->precision)
		*prefix = ' ';
	if (!spec->zero)
		*prefix = ' ';
	if (spec->zero)
		spec->min_width = spec->zero_offset;
	if (spec->precision > spec->min_width)
		spec->min_width = spec->precision;
	return (len);
}

/* Function to print the long, signed integer. We init the total counter
 * first, then handle the min_width specifier. */

static int	print_int(int len, long l, t_spec spec)
{
	int	total;

	total = 0;
	if (l == 0 && spec.min_width && spec.min_width < len)
		total += ft_putchar(' ');
	else if (l == 0 && spec.dot && !spec.precision && spec.min_width >= len)
		total += ft_putchar(' ');
	else if (!(l == 0 && spec.dot && !spec.precision))
		total += ft_putnum(l);
	return (total);
}

/* Prints long signed integers. We start out by sorting any formatting 
 * specifiers that were passed to the function, then print a + if our
 * ft_printf() function has specified we put one there. We add x ammount of 0s
 * until we get to whatever the min width is, and then we finally get around to
 * doing the actual numbers with our print_int() function. We handle the offset
 * next and then return the total value for the functions final output. */

int	ft_printnum(long l, t_spec spec)
{
	int		total;
	int		len;
	int		prec;
	char	prefix;

	total = 0;
	len = values(&prefix, &prec, &spec, l);
	while (prefix == ' ' && prec + total < spec.min_width)
		total += ft_putchar(' ');
	if (l < 0)
		total += print_neg(&l, &len, spec);
	else if (spec.space && l >= 0 && !spec.plus && !spec.dot)
		total += ft_putchar(' ');
	else if (spec.plus && l >= 0 && !spec.dot)
		total += ft_putchar('+');
	while (len + total < spec.min_width)
		total += ft_putchar('0');
	total += print_int(len, l, spec);
	while (total < spec.offset)
		total += ft_putchar(' ');
	return (total);
}
