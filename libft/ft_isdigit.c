/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:47:14 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/21 11:35:47 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks to see if something is a number between 0 or 9. Not sure what else
 * to tell you really.*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
