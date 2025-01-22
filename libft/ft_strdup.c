/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:24:51 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 13:27:25 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strdup() duplicates the string 's1', allocating memory for the copy.
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len_s1;
	char	*ptr;

	i = 0;
	len_s1 = ft_strlen (s1);
	ptr = malloc(sizeof (char) * (len_s1 + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[]= "hello world!";
	printf("FT_STRDUP = %s", ft_strdup(s1));
}
*/
