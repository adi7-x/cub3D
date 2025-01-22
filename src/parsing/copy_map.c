/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:21:55 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:30 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	count_strings(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
		i++;
	return (i);
}

char	**ft_copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		cont;

	i = 0;
	cont = count_strings(map);
	new_map = malloc(sizeof(char *) * (cont + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**copy_map(char **map)
{
	char	**new_map;
	size_t	cont;
	int		i;

	i = 0;
	cont = 0;
	while (map[i])
	{
		if (cont < ft_strlen(map[i]))
			cont = ft_strlen(map[i]);
		i++;
	}
	new_map = ft_copy_map(map);
	return (new_map);
}
