/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:13:50 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/21 14:55:49 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a string representing the integer
 * recieved as an argument. Negative numbers must be handled. The function 
 * returns NULL if the allocation fails.
 *
 * In human readable form, ft_itoa() allocates memory and returns a new, null
 * terminated string of characters that is the char equivalent of the integer
 * that was passed in to it. It also has to handle negative numbers. If it
 * can't allocate the memory it should return NULL.
 *
 * First of all, if you're an eejut like me you'll need to read up on how to 
 * convert integers to ascii and vice versa. I used this:
 * https://www.cs.colostate.edu/~fsieker/misc/NumberConversion.html
 *
 * So first thing we're gunna do is make ourselves a likkle helper function to
 * count and return the number of digits passed to the ft_itoa() function.
 * First we just check to see if the number is zero, and if it is we also return
 * zero. If it's more than zero, we're going to go in to a while loop that will
 * divide the number until it reaches zero. Once it does the counter will stop
 * and it's value will be the number of numbers in the number. Lol. You get me
 * though right? Like if n was 42, n / 10 is 4.2 (counter is 1), 4.2 / 10 = 0.42
 * (counter is 2) but now it can't go any further so that's it because n is no
 * longer > 0.
 *
 * Oh yeah, we're using unsigned int here too because we don't care about the
 * value being positive or negative, we just want to count the total number of
 * digits.*/

#include "libft.h"

static size_t	ft_number_length(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (n + 1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/* And now for the main event. We got ourselves a likkle isneg variable here 
 * that's going to tell us if the number is a negative or not. If it's less 
 * than we set our tmp variable to negative, then flip isneg to 1, or true.
 * Otherwise we'll just store our nbr in the tmp variable and move along.
 * We'll use our first helper function in here to get the length of the number
 * (obviously) and then add whatever value isneg has to give us room to add a
 * - symbol if needed. Then we use our own ft_calloc() function to allocate
 * memory for the string we'll return at the end of all this. A quick null chec
 * and then we jump in to a decrementing while loop. We're counting backwards
 * so it writes out the string in the right order. We just take whatever is in
 * the current position in the string, modulo it by 10 then add '0' (aka  an 
 * ASCII value of 48) to it to get is the right character for that number, then
 * divide the number stored in tmp by 10 to move to the next number, repeating
 * the loop until we hit the last number we want to print. Then if the number
 * was a negative number we'll add a - symbol at the start of the string before
 * finally returning the string, an ASCII representation of the number we passed
 * to the function. */

char	*ft_itoa(int nbr)
{
	unsigned int	tmp;
	size_t			len;
	char			*str;
	int				isneg;

	isneg = 0;
	if (nbr < 0)
	{
		tmp = -nbr;
		isneg = 1;
	}
	else
		tmp = nbr;
	len = isneg + ft_number_length(tmp);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}
