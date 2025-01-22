/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:20 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:18:54 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	handel_x(t_data *data)
{
	data->wall_x = data->player_y + data->new_des * data->ray_dir_y;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * TEXTURE_WIDTH);
	if (data->step_x == -1)
	{
		data->tex_y = ((data->i - data->start) * TEXTURE_HEIGHT) / (data->end
				- data->start);
		data->color = get_texture_color(&data->west, data->tex_x, data->tex_y);
	}
	else
	{
		data->tex_y = ((data->i - data->start) * TEXTURE_HEIGHT) / (data->end
				- data->start);
		data->color = get_texture_color(&data->east, data->tex_x, data->tex_y);
	}
}

void	handel_y(t_data *data)
{
	data->wall_x = data->player_x + data->new_des * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * TEXTURE_WIDTH);
	if (data->step_y == -1)
	{
		data->tex_y = ((data->i - data->start) * TEXTURE_HEIGHT) / (data->end
				- data->start);
		data->color = get_texture_color(&data->north, data->tex_x, data->tex_y);
	}
	else
	{
		data->tex_y = ((data->i - data->start) * TEXTURE_HEIGHT) / (data->end
				- data->start);
		data->color = get_texture_color(&data->south, data->tex_x, data->tex_y);
	}
}

void	handel_tex(t_data *data)
{
	data->i = 0;
	while (data->i < fmin(data->start, WINDOW_HEIGHT))
	{
		put_pixel(data, data->ray_num, data->i, data->ceiling_color);
		data->i++;
	}
	data->i = fmax(0, data->start);
	while (data->i < fmin(data->end, WINDOW_HEIGHT))
	{
		if (data->side == 0)
			handel_x(data);
		else
			handel_y(data);
		put_pixel(data, data->ray_num, data->i, data->color);
		data->i++;
	}
	data->i = fmax(data->end, 0);
	while (data->i < WINDOW_HEIGHT)
	{
		put_pixel(data, data->ray_num, data->i, data->floor_color);
		data->i++;
	}
}
