/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:53 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:19:14 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	int_rays(t_data *data)
{
	data->ray_dir_x = cos(data->current_angle);
	data->ray_dir_y = sin(data->current_angle);
	data->map_x = (int)data->player_x;
	data->map_y = (int)data->player_y;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
}

void	calculate_dest(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->player_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->player_y)
			* data->delta_dist_y;
	}
}

void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
	if (data->side == 0)
		data->distance = ((data->map_x - data->player_x + (1 - data->step_x)
					/ 2) / data->ray_dir_x);
	else
		data->distance = ((data->map_y - data->player_y + (1 - data->step_y)
					/ 2) / data->ray_dir_y);
	data->new_des = data->distance * cos(data->current_angle
			- data->player_angle);
}

void	draw_direction_line(t_data *data)
{
	data->current_angle = data->player_angle - (FOV / 2);
	data->ray_num = 0;
	while (data->ray_num <= WINDOW_WIDTH)
	{
		int_rays(data);
		calculate_dest(data);
		dda(data);
		if (data->new_des <= 0.2)
			data->new_des = 0.2;
		data->wall_height = (WINDOW_HEIGHT * 0.7 / data->new_des);
		data->start = (WINDOW_HEIGHT - data->wall_height) / 2;
		data->end = (WINDOW_HEIGHT + data->wall_height) / 2;
		data->i = 0;
		handel_tex(data);
		data->current_angle += ANGLE_STEP;
		data->ray_num++;
	}
}
