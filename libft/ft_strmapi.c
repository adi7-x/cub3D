/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:58:48 by adbourji          #+#    #+#             */
/*   Updated: 2023/11/29 11:56:00 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strmapi() applies the function 'f' to each character of the string 's',
 * creating a new string with the modified characters.
 * Returns the newly allocated string or NULL if allocation fails.
*/

/*
char ft_ftest(unsigned int a, char b)
{
	if (b >= 'a' && b <= 'z')
		return (b - 32);
	return (b);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}

/*
#include <stdio.h>
int	main(void) 
{
	const char *input_string = "Hello, World!";

	char *result = ft_strmapi(input_string, ft_ftest);


	printf("Chaîne d'origine : %s\n", input_string);
	printf("Nouvelle chaîne   : %s\n", result);

	free(result);

	return (0);
}
*/
