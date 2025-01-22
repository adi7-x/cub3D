/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:22:29 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 11:32:31 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * the ft_putchar_fd() writes character 'c' to the given file descriptore.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int fd;
	fd = open("text.txt" ,O_CREAT | O_WRONLY);
	ft_putchar_fd('3', fd);
	close(fd);
}
*/
