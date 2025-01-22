/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:12:08 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:30:43 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strrchr() function is identical to strchr(),
 * except it locates the last occurrence of c.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	if ((char) !c)
		return ((char *) &s[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[]="ASDF1GHF2JKL";
	int c = 'F';
	printf("%s\n", ft_strrchr(str, c));
}
*/
