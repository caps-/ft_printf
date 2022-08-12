/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:17:00 by pwhittin          #+#    #+#             */
/*   Updated: 2022/06/06 15:19:03 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* The first helper function inside this thing, and it's nothing too crazy at
 * all. We check to see if the second element of the str array is whatever
 * character (because the first is going to be %), then just runs the
 * corresponding function on the rest of the string. For the ft_printbase()
 * function we send it 0 if it's lowercase and 1 if it's uppercase. Also,
 * ft_printf() has to return a value for the number of characters printed, so
 * every single function also has to return a total. Keep that in mind because
 * I won't mention it in other comments. */

int	processnorm(const char *str, va_list *args, t_spec spec)
{
	int	total;

	total = 0;
	if (str[1] == 'c')
		total += ft_printchar(va_arg(*args, int), spec);
	else if (str[1] == 's')
		total += ft_printstr(va_arg(*args, char *), spec);
	else if (str[1] == 'p')
		total += ft_printptr(va_arg(*args, void *), spec);
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_printnum(va_arg(*args, int), spec);
	else if (str[1] == 'u')
		total += ft_printunum(va_arg(*args, unsigned int), spec);
	else if (str[1] == 'x')
		total += ft_printbase(va_arg(*args, int), 0, spec);
	else if (str[1] == 'X')
		total += ft_printbase(va_arg(*args, int), 1, spec);
	else if (str[1] == '%')
		total += ft_putchar('%');
	return (total);
}

/* Processing the flags next, aslo a pretty simple one. We just set whatever
 * flag specifier value to 1 (they're initialized to 0) to tell the program
 * it's been called, thn the rest is just the different formatting options,
 * offset, precision and ezro offset.*/

void	processflags(t_spec *spec, const char *str, int *i)
{
	if (str[1] == '#')
		spec->hash = 1;
	else if (str[1] == ' ')
		spec->space = 1;
	else if (str[1] == '+')
		spec->plus = 1;
	else if (str[1] == '-')
	{
		spec->offset = atoi_custom(str + 2, i);
		spec->minus = 1;
	}
	else if (str[1] == '.')
	{
		spec->precision = atoi_custom(str + 2, i);
		spec->dot = 1;
	}
	else if (str[1] == '0')
	{
		spec->zero_offset = atoi_custom(str + 2, i);
		spec->zero = 1;
	}
}

/* This guy sends the input of ft_printf() to the appropriate processing
 * functions. While any of the characters specified in the while loop are
 * present it'll either process whatever flags are specified, or it'll just
 * format it to give it the min width that was given. If it's not working on
 * any of those it sends the string to the processnorm() function which
 * handles the normal format specifiers. */

int	startprocess(const char *str, va_list *args, int *i)
{
	int		total;
	t_spec	spec;

	total = 0;
	init_spec(&spec);
	while (in_str(str[(*i) + 1], "0123456789# -+."))
	{
		if (in_str(str[(*i) + 1], "# 0-+."))
			processflags(&spec, str + (*i), i);
		else
		{
			spec.min_width = atoi_custom(str + (*i) + 1, i);
			(*i)--;
		}
		(*i)++;
	}
	total += processnorm(str + (*i), args, spec);
	(*i)++;
	return (total);
}

/* Where it all starts. Once the program is run it checks for the % char and
 * kicks off the startprocess() function to ..you know ..start processing the
 * format specifiers and flags. If it's not there it'll just write out the
 * string to the output using ft_putchar(). Both of those also add up the
 * characters used and the value is returned once ft_printf() has finished.*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			total += startprocess(str, &args, &i);
		else
			total += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (total);
}
