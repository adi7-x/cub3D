/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:49:07 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:37 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_strlcat() fun adds a string from the source to the destination
 * with a specific size limit & ensuring proper '\0'
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ds_len;
	size_t	sr_len;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dst);
	ds_len = ft_strlen(dst);
	sr_len = ft_strlen(src);
	if (dstsize == 0 || dstsize <= ds_len)
		return (sr_len + dstsize);
	while (src[i] && i < dstsize - ds_len - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ds_len + sr_len);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[]="hello world!";
	char dst[] = "Salut le Monde!";
	ft_strlcat(dst, src, 30);
	printf("%zu\n", ft_strlcat(dst, src, 30));
	printf("%s\n", dst);
}
*/
