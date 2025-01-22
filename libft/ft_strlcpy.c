/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:42:07 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:46:48 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_styrlcpy() fun copies from the source to the destination,
 * with a specified size limit.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char src[]="hello world!";
	char dst[] = "Ciao Mondo!";

	puts(dst);
//	ft_strlcpy(dst, src, 60);

//	printf("----------\n%s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, 0));
}
*/
