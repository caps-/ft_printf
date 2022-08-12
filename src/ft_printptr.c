/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:29:09 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/07 14:27:27 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Our function to print pointers.
 *
 * As we're going to be pointing to a memory address, we nede to return a hex
 * value. The first if loop runs if the address is longer than 16 digits, so
 * we do the old divide/modulo trick to bring it back down. Once that's got
 * it down to size, or if the address was already 16 or lower, we go in to
 * an else loop to print it out. We've got a character variable 'c' here which
 * will be the latter in the address. Basically if the number ends up being
 * greater than 9 we just add 87 to the ascii value which will give us the
 * correct letter. */

static int	print_longhex(long unsigned addr)
{
	int		total;
	char	c;

	total = 0;
	if (addr >= 16)
	{
		total += print_longhex(addr / 16);
		total += print_longhex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87); //this gives you the right letter
		write(1, &c, 1);
		total++;
	}
	return (total);
}

/* Simple recursive function to get the size (or length, not talking about 
 * memory size here) of the hex value. */

static int	hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += hex_size(addr / 16);
		total += hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

/* We need to convert the address to characters, so we cast the pointer's
 * address as a long unsigned int for the print_longhex() function to handle,
 * and then add "0x" at the start.*/

int	ft_printptr(void *ptr, t_spec spec)
{
	long	addr;
	int		len;
	int		total;

	addr = (long unsigned)ptr; //cast pointer to long unsigned
	len = hex_size(addr) + 2; //make room for the 0x
	total = 0;
	while (len + total < spec.min_width)
		total += ft_putchar(' ');
	total += ft_putstr("0x");
	total += print_longhex(addr); //write out the address
	while (total < spec.offset)
		total += ft_putchar(' ');
	return (total);
}
