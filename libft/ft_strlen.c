/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:27:47 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 17:32:00 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * The strlen() function computes the length of the string s.
 * The strnlen() function attempts to compute the length of s.
 * But never scans beyond the first maxlen bytes of s.
*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s;
	size_t		custpm_length;
	size_t		standard_length;

	s = NULL;
	custpm_length = ft_strlen(s);
	standard_length = strlen(s);
	if (custpm_length == standard_length)
		printf("Correct!\n");
	printf("--------------\n");
	printf("Custom strlen : %zu\n", custpm_length);
	printf("Standard strlen : %zu\n", standard_length);
}
*/
