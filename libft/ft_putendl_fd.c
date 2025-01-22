/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:16:47 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 11:44:27 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_putendl_fd() writes the string 's' followed by a '\n' to the fd.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*
#include <fcntl.h>
int main()
{
	int	fd;

	fd = open("test.txt", O_CREAT | O_WRONLY);
	ft_putendl_fd("NEVADA", fd);
	close (fd);
}
*/
