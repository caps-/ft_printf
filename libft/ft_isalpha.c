/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:32:54 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/21 11:33:12 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks if whatever is passed to the int paramater is either an uppercase or
 * lowercase letter and returns 0 if it isn't.*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
