/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:04:43 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 13:41:17 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The ft_strjoin() concatenates strings 's1' & 's2' into new string.
 * Returns the newly allocated concatenated string or NULL if allocation fails.
*/

char	*ft_strjoin(char *remainder1, char *buffer1)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder1)
		return (ft_strdup(buffer1));
	res = malloc(ft_strlen(remainder1) + ft_strlen(buffer1) + 1);
	if (!res)
		return (NULL);
	while (remainder1[i])
	{
		res[i] = remainder1[i];
		i++;
	}
	while (buffer1[j])
		res[i++] = buffer1[j++];
	res[i] = '\0';
	free(remainder1);
	return (res);
}

/*
#include <stdio.h>
int main()
{
	char *s1 = "hello";
	char *s2 = "World!";
	char *new_s;
	
	new_s = ft_strjoin(s1, s2);

	printf("s1     =      %s\n\n", s1);
	printf("s2     =      %s\n\n", s2);
	printf("new_s  =      %s", new_s);

}
*/
