/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:18:20 by pwhittin          #+#    #+#             */
/*   Updated: 2022/02/20 13:49:28 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Uses malloc() to allocate and return an array of strings obtained by
 * splitting 's' using the character 'c' as a delimiter. The array must end
 * with a NULL pointer.
 *
 * Fuckin look at this chonker of a function. OK, let's break it down.
 * 
 * First thing we need is a function to get the number of characters in all of
 * the split substrings. Remember, we've cut them using a delimiter character, 
 * so we need to basically count the total characters we have not uncluding the 
 * delimiter. Computers are dumb so you gotta tell em to do shit like that. So
 * we'll use two variables here; in_substr, which we're goign to use to indicate
 * when a new substring is found, and a simple counter to count the characters.
 * We get a while loop going here that works as long as there's a string passed.
 * Our in_substr varialble is initialized to 0 which we'll take to mean 'false'.
 * So the first if statement says if in_substr is 1, or yes we are in in a
 * substring, and the position in s we're in holds the delimiter we must actually
 * be at the END of the substring, so it sets in_substr to 0. The next if checks
 * to see if in_substr is 0 and we're NOT at the delimiter. If that's the case
 * we must be in a substring so it sets in_substr to 1 and adds to the count.
 * Because in_substr is now set to one it exit's the if loop and the main while
 * loop moves to increment over to the next spot in the string, after which
 * that whole process begins again. Eventually we hit the end of s, and our
 * counter will have added up all the characters which is what our return value
 * will be. I know that's a bit of a messy explanation but to be honest I don't
 * know coding intuitively enough yet to explain it better lol, sorry.*/

#include "libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	int		in_substr;
	size_t	count;

	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (in_substr == 1 && *s == c)
			in_substr = 0;
		if (in_substr == 0 && *s != c)
		{
			in_substr = 1;
			count++;
		}
		s++;
	}
	return (count);
}

/* Next helper function is just a simple string length ..counter? Size getter? 
 * It's simple enough, as long as there's something passed to *s it'll just 
 * increment the len counter and then move along to the next position until it 
 * hits the delimiter, returning the final length value. Easy peasy.*/

static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

/* Lol I was literally just talking to another student in the eleveator about
 * this function. Don't worry, it's giving almost everyone grief. Anyway, we're
 * up to the actual ft_split() function now, so let's get it done and dusted.
 * Quick check to make sure a string has actually been passed to the function,
 * then we set the value of our strcount variable using the first helper we
 * made above. Next we gotta allocate memory for our final array of strings to
 * return, so we'll use malloc with our ft_strcount() helper again. Then we got
 * a lil if statement that just checks to make sure the allocation worked and 
 * returns NULL if it didn't. Next we have pretty funky while loop, so let's
 * break that down. 
 *
 * The loop decrements down along strcount, so we're adding
 * substrings in reverse (think right to left) so they'll be returned in the
 * correct order (left to right). The first while statement we hit moves to
 * the next position in s if it hits the delimiter, which will be the start
 * of a substring we need to copy over to the output. We've already made 
 * another function in our library called ft_substr() and we can use that to 
 * actually get the substring, and thanks to the way it works we can use the 
 * ft_len() helper we wrote above to tell it exactly what to copy. Check out the
 * comments in that file to find out how it works. 
 *
 * first while moves to the next position. Then ft_substr starts from that s
 * position and uses ft_len to tell the program how far along to count. */

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		strcount;
	int		i;

	if (!s)
		return (NULL);
	strcount = ft_strcount(s, c);
	strs = (char **) malloc(sizeof(*strs) * (ft_strcount(s, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (strcount--)
	{
		while (*s && *s == c)
			s++;
		strs[i] = ft_substr(s, 0, ft_len(s, c));
		if (!strs[i])
			return (NULL);
		s = s + ft_len(s, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
