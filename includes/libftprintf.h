/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:22:44 by pwhittin          #+#    #+#             */
/*   Updated: 2022/04/07 15:27:43 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_spec
{
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		dot;
	int		min_width;
	int		zero;
	int		zero_offset;
	int		offset;
	int		precision;
}	t_spec;

int		ft_printf(const char *str, ...);
int		ft_printchar(char c, t_spec spec);
int		ft_printstr(char *str, t_spec spec);
int		ft_printptr(void *ptr, t_spec spec);
int		ft_printnum(long l, t_spec spec);
int		ft_printunum(unsigned long n, t_spec spec);
int		ft_printbase(int n, int uppercase, t_spec spec);
int		in_str(char c, char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnum(long l);
int		atoi_custom(const char *str, int *j);
void	init_spec(t_spec *spec);

#endif
