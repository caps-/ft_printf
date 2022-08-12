/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:19:18 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/06 17:32:51 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function f to each character of the stringg passed as an arg,
 * and passing its index as first arg. Each character is passed by address to
 * f to be modified if necessary. 
 * 
 * We do a quick null check first, jump in to a while loop. We just apply the
 * function to whatever's in the current address of s[i] then increment on to 
 * then next one until we hit the null terminator. Once that happens the
 * function is done.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
