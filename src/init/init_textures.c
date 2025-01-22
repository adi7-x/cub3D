/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:32 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:19:42 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	load_texture(t_data *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
	{
		printf("problem in image\n");
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length,
			&tex->endian);
}

void	load_all_textures(t_data *data)
{
	load_texture(data, &data->north, data->no_texture);
	load_texture(data, &data->south, data->so_texture);
	load_texture(data, &data->west, data->we_texture);
	load_texture(data, &data->east, data->ea_texture);
}
