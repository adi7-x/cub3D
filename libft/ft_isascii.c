/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:33:36 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:12:34 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The isascii() function tests for an ASCII character.
 * which is any character between 0 & octal 0177 inclusive.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
