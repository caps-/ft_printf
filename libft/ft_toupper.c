/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:19:06 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/07 18:21:03 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts a lowercase letter to an uppercase letter.
 *
 * Take the character, subtract 32 from it's ascii value and we end up with
 * the uppercase version.*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
