/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:32:50 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 20:43:38 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memcpy() function copies n bytes from memory area src to memory area dst..
 * If dst & src overlap, behavior is undefined ..
 * Applications in which dst & src might overlap should use memmove() instead.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0 ;
	if (!dst && !src)
	{
		return (0);
	}
	if (dst != src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	int	src[]={1, 5, 2};
//	int	dst[]={3, 9, 7};

	int *res = ft_memcpy(src + 2, src, 2);
	int i = 0;
	while (i < 3)
	{
		printf("%d ", res[i]);
		i++;
	}
//	printf("%d %d %d\n", dst[0], dst[1], dst[2]);
}
*/
