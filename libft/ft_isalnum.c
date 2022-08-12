/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:48:57 by pwhittin          #+#    #+#             */
/*   Updated: 2022/01/26 17:10:14 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks to see if the int paramater is either a character or a digit. We can
 * use two other functions we wrote here to make life simpler, check out the
 * respective files for more info on what they both do. */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
