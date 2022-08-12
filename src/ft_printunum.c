/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:21:40 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/07 15:12:51 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Prints unsigned long integers. 
 *
 * Our first function is what actually does the printing, and it's nothing 
 * particularly tricky, just converting the number to alphanumeric characters
 * and ..like ..printing them.*/

int	print_unsigned(unsigned long l)
{
	int				total;
	unsigned long	number;

	total = 0;
	number = l;
	if (number > 100)
		total += print_unsigned(number / 10);
	else if (number == 100)
		total += ft_putstr("10");
	else if ((number / 10) > 0)
		total += ft_putchar((number / 10) + '0');
	total += ft_putchar((number % 10) + '0');
	return (total);
}

/* Gets the length of the digit. Shoulda called it digitlen() or something
 * but who knows wtf I was thinking when I wrote this. Pitfalls of grabbing
 * random lines from stackexchange I guess lol. Anyway it's pretty simple, we
 * just a null check and a counter. */

static int	digitnbr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/* This guy handles all the specifiers and tbh is kinda neat. If the precision
 * is greater than the length we make 'prec' point to our precision struct and
 * throw a '0' in to our prefix pointer. Similar kinda deal for our zeroing.
 * The other stuff should be pretty self explanitory, I just think it's kinda
 * cool lol. */

static int	vals(char *prefix, int *prec, t_spec *spec, unsigned long n)
{
	int	len;

	len = digitnbr(n);
	*prec = len;
	if (spec->precision > len)
		*prec = spec->precision;
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

/* Print unsigned integers */

static int	print_un(int len, unsigned long n, t_spec spec)
{
	int	total;

	total = 0;
	if (n == 0 && spec.min_width && spec.min_width < len)
		total += ft_putchar(' ');
	else if (n == 0 && spec.dot && !spec.precision && spec.min_width >= len)
		total += ft_putchar(' ');
	else if (!(n == 0 && spec.dot && !spec.precision))
		total += print_unsigned(n);
	return (total);
}

/* The main function here. We don't need to give prefix and prec values here
 * because we're actually sending them to our vals() function which will do
 * that for us. Normally you would get an error if you tried to compile but
 * we're cool here because of that. Vals is explained above.  */

int	ft_printunum(unsigned long n, t_spec spec)
{
	int		total;
	int		len;
	int		prec;
	char	prefix;

	total = 0;
	len = vals(&prefix, &prec, &spec, n);
	while (prec + total < spec.min_width)
		total += ft_putchar(prefix);
	while (len + total < spec.min_width)
		total += ft_putchar('0');
	total += print_un(len, n, spec);
	while (total < spec.offset)
		total += ft_putchar(' ');
	return (total);
}
