/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:37:29 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 19:01:40 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the strchr() function used to find the first occurrence..
 * of a character in a given string.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char string[]= "ASDF1GHF2JKL";
	int c = 'F';
	printf("%s\n", ft_strchr(string , c));
}
*/
