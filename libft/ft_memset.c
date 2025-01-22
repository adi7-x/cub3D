/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:42:11 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:08:01 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memeset() function writes len bytes of value c..
 * (converted to an unsigned char) to the string b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (len > 0)
	{
		ptr[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
/*
#include <stdio.h>

int main ()
{
	int arr[] = {42};
	
	printf("Before ft_memset : %d\n", arr[0]);
	
	printf("========================\n");

	ft_memset((char *)arr, 57, 1);
	
	ft_memset((char *)arr + 1 , 5, 1);

	printf("After ft_memset : %d\n", arr[0]);
}
*/
