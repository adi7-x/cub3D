/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:35 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:14:08 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_w(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\t')
		{
			count++;
			while (str[i] != '\0' && str[i] != c && str[i] != '\t')
				i++;
		}
		else if (str[i] == c || str[i] == '\t')
			i++;
	}
	return (count);
}

char	**ft_split2(char *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	p = (char **)malloc((cont_w(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] == c || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\t' && s[i] != '\0' && j++ >= 0)
			i++;
		p[n++] = ft_substr(s, i - j, j);
	}
	p[n] = NULL;
	return (p);
}

static int	cont_w1(const char *str)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_whitespace(str[i]))
		{
			count++;
			while (str[i] != '\0' && !is_whitespace(str[i]))
				i++;
		}
		else if (is_whitespace(str[i]))
			i++;
	}
	return (count);
}

char	**ft_split1(char *str)
{
	char	**p;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	p = (char **)malloc((cont_w1(str) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		while (is_whitespace(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		j = 0;
		while (!is_whitespace(str[i]) && str[i] != '\0' && j++ >= 0)
			i++;
		p[n++] = ft_substr(str, i - j, j);
	}
	p[n] = NULL;
	return (p);
}
