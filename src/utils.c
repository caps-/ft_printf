/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:32:34 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/07 12:39:10 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* Initialize the speicifiers to 0.*/

void	init_spec(t_spec *spec)
{
	spec->hash = 0;
	spec->space = 0;
	spec->plus = 0;
	spec->minus = 0;
	spec->dot = 0;
	spec->min_width = 0;
	spec->zero = 0;
	spec->zero_offset = 0;
	spec->offset = 0;
	spec->precision = 0;
}

/* Just re-writing ye olde ft_atoi function because I forgot to put it in the
 * libft library. */

int	atoi_custom(const char *str, int *j)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		(*j)++;
	}
	return (num);
}

/* Used in the main ft_printf() function. We just use this guy to check to see
 * if any of the characters we want are in the string & return 1 if they are.*/

int	in_str(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

/* Recursive function used in ft_printnum() for printing a signed integer. */

int	ft_putnum(long l)
{
	int		total;
	long	num;

	total = 0;
	num = l;
	if (l < 0)
	{
		total += ft_putchar('-');
		num = -l;
	}
	if (num > 100)
		total += ft_putnum(num / 10);
	else if (num == 100)
		total += ft_putstr("10");
	else if ((num / 10) > 0)
		total += ft_putchar((num / 10) + '0');
	total += ft_putchar((num % 10) + '0');
	return (total);
}	
