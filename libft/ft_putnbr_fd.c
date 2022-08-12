/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.or.au>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:11:07 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/21 14:38:37 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the integer 'n' to the given file descriptor.
 *
 * In other words it writes the ascii representation of an int to a given file 
 * descriptor.
 * 
 * Right, so first of all, if the number is negative, we'll manually add our own
 * negative symbol, then multiply the number by -1 to change it to a positive
 * number so we can convert the actual digits to their ASCII representations.
 *
 * Once that's done we go in to an if loop. If the number is greater than 10
 * we'll keep dividing it by 10, after which we'll take the modulo of that and
 * add the ASCII value for '0' to it, or 48, which will give us the ASCII value
 * for the actual digit. We'll use our ft_putchar_fd() function form the lib
 * to write that number on the screen, then go back to the start of the function
 * and do it all again for the next number along until we've printed out the 
 * last digit.*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd('0' + (number % 10), fd);
}
