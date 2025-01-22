/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:42 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:15:31 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_whitespace(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (is_whitespace(str[i]))
	{
		i++;
	}
	if (str[i] == '\0')
		return (0);
	return (1);
}
