/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:24:34 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/07 18:19:46 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts an uppercase letter to a lowercase letter.
 *
 * Literally just take c and add 32 to it, the new ascii value will be it's
 * lowercase version.*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
