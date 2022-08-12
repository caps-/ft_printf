/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:15:59 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/15 11:34:38 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts a string to integer type and discards whitepsace and non printable
 * characters. 
 *
 * Aah, ye olde atoi function. Start with a null check like we always do. A
 * while loop to check for whitespace/tabs etc, just using an actual space then
 * ascii values for that. Next is a little if loop that we're going to use the
 * value of at the end of the function. Basically if the string has a negative
 * sign at the start we know it's going to be represetnging a negative value, so
 * we'll have to convert the integer to a negative value too. If that's the
 * case we'll set the sign value to negative (-1 in this case), then move on.
 * The funal while loop is just to convert the ascii characters to actual ints.
 * Subtracting 48 from the ascii value for the number gives you the actual int
 * of that char, and the whole 0 * 10 thing is basically to "shift" the previous
 * result to the left once a new digit has been detected so we can add that to
 * the number also. Finally we multiply it by the sign value, so if it's 
 * negative it will return an actual negative integer. Nice!*/

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (*str == 0)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num = num + str[i] - 48;
		i++;
	}
	return (num * sign);
}
