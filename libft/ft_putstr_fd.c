/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:59:50 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 11:36:40 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_putstr_fd() writes string 's' to the specifies fd.
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("test0.txt", O_CREAT | O_WRONLY);
	printf("%d\n", fd);
	ft_putstr_fd("abc", fd);
}
*/
