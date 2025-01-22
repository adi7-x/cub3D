/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:51 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:35:30 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	valide_extension(char *path, char *extension)
{
	int	len;

	if (path == NULL)
		return (1);
	len = ft_strlen(path) - 4;
	if (ft_strcmp(path + len, extension))
	{
		printf("Error\nInvalid path extension %s \n", path);
		return (1);
	}
	return (0);
}

void	ft_check_data(t_data *data)

{
	if (data->map == NULL)
	{
		printf("Error\nMissing map\n");
		ft_free_data(data);
	}
	if (!data->no_texture || !data->so_texture || !data->we_texture
		|| !data->ea_texture)
	{
		printf("Error\nMissing texture path\n");
		ft_free_data(data);
	}
	if (data->floor_color == -1 || data->ceiling_color == -1)
	{
		printf("Error\nMissing color\n");
		ft_free_data(data);
	}
}

void	check_path_extension(t_data *data)
{
	int	flag;

	flag = 0;
	ft_check_data(data);
	if (valide_extension(data->no_texture, ".xpm"))
		flag = 1;
	else if (valide_extension(data->so_texture, ".xpm"))
		flag = 1;
	else if (valide_extension(data->we_texture, ".xpm"))
		flag = 1;
	else if (valide_extension(data->ea_texture, ".xpm"))
		flag = 1;
	if (flag == 1)
		ft_free_data(data);
}
