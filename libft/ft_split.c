/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:43:08 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/16 01:54:13 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_split() fun splits string 's' using delimiter 'c'.
 * returns the array of substrings on NULL in allocation fails.
*/

static size_t	ft_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**ft_free(char **str)
{
	while (*str)
	{
		free(*str);
		str--;
	}
	free(str);
	return (0);
}

static char	**ft_help(char **ptr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			ptr[k++] = ft_substr(s, j, i - j);
			if (!ptr[k - 1])
			{
				ft_free(ptr);
				return (NULL);
			}
		}
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_count((char *)s, c);
	ptr = (char **)malloc((i + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[i] = NULL;
	ptr = ft_help(ptr, s, c);
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	char	*str;
	char	dl;
	int		i;
	char	**res;

	str = ",,,,,,split,,,this,for,me,!";
	dl = ',';
	i = 0;
	res = ft_split(str, dl);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
}
*/
