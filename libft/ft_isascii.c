/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:54:57 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/21 11:34:40 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check to see if the int is something that is represented by an ASCII value.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
