/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:53:34 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:08:34 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memchr() function locates the first occurrence of c
 *     (converted to a unsigned char) in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		ch;

	i = 0;
	ptr = s;
	ch = c;
	while (i < n)
	{
		if (ptr[i] == ch)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char	*s;
	int		c;

	s = "hello world!";
	c = 'l';
	printf("%s\n-------------------\n", ft_memchr(s, c, 5));
}
*/
