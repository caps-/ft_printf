/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:22:46 by pwhittin          #+#    #+#             */
/*   Updated: 2022/08/23 15:36:29 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function handles printing numbers in hex..*/

#include "../includes/libftprintf.h"

/* Finds and returns the length/size of hex numbes.*/

static int	hexsize(int n)
{
	int				total;
	unsigned int	len;

	total = 0;
	len = n;
	if (len >= 16)
	{
		total += hexsize(len / 16);
		total += hexsize(len % 16);
	}
	else
		total ++;
	return (total);
}

/* Handles specifier values.*/

static int	vals(char *prefix, int *prec, t_spec *spec, int n)
{
	int	len;

	len = hexsize(n);
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

/* This guy just does the ol' divide/modulo trick to convert a number to a
 * string so we can print it using characters including a-f.  */

static int	print_base(int n, char *base)
{
	unsigned int	base_len;
	unsigned int	num_len;
	int				total;

	total = 0;
	num_len = n;
	base_len = ft_strlen(base);
	if (num_len >= base_len)
	{
		total += print_base(num_len / base_len, base);
		total += print_base(num_len % base_len, base);
	}
	else
	{
		total += ft_putchar(base[num_len]);
	}
	return (total);
}

/* Figures out the actual hex number to print. Format di ting, then we send
 * the characters we want to use to the print_base() function. */

static int	print_x(int uppercase, int len, int n, t_spec spec)
{
	int	total;

	total = 0;
	if (n == 0 && spec.min_width && spec.min_width < len)
		total += ft_putchar(' ');
	else if (n == 0 && spec.dot && !spec.precision && spec.min_width >= len)
		total += ft_putchar(' ');
	else if (!(n == 0 && spec.dot && !spec.precision))
	{
		if (uppercase)
			total += print_base(n, "0123456789ABCDEF");
		else
			total += print_base(n, "0123456789abcdef");
	}
	return (total);
}

/* First while loop here handles the precission and width and all that. Cool.
 * Next we output either 0X or 0x depending on if it's been flagged as
 * uppercase or not, then we move on to the actual hex number to print.*/

int	ft_printbase(int n, int uppercase, t_spec spec)
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
	if (spec.hash && n != 0)
	{
		if (uppercase)
			total += ft_putstr("0X");
		else
			total += ft_putstr("0x");
	}
	total += print_x(uppercase, len, n, spec);
	while (total < spec.offset)
		total += ft_putchar(' ');
	return (total);
}
