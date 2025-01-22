/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:52:11 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:29:35 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memmove() function copies a block of memory from one location
 * to another..
 * it's similar to the memcpy() fun , but it handles 'OVERLAPPING'..
 * memory egions correctly .
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	int arrd[]={1, 2, 3};
	int arrs[]={5, 9, 7};

	int *res = memmove(arrd, arrs, 5);
	printf("%d %d\n", res[0], res[1]);
}
*/
