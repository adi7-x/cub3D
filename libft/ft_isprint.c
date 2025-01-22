/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:15:08 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/28 12:15:03 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_isprint() checks if the 'c' is a printable character in the ASCII range.
 * Returns 1 if 'c' is a printable character otherwise 0.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
