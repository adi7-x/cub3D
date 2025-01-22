/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:07 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:18:23 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	handel_moves(int key, t_data *data)
{
	if (key == KEY_W)
	{
		data->new_x += data->dir_x * 0.10;
		data->new_y += data->dir_y * 0.10;
	}
	else if (key == KEY_S)
	{
		data->new_x -= data->dir_x * 0.10;
		data->new_y -= data->dir_y * 0.10;
	}
	else if (key == KEY_D)
	{
		data->new_x -= data->dir_y * 0.10;
		data->new_y += data->dir_x * 0.10;
	}
	else if (key == KEY_A)
	{
		data->new_x += data->dir_y * 0.10;
		data->new_y -= data->dir_x * 0.10;
	}
	else if (key == KEY_LEFT)
		data->player_angle -= ROTATION_SPEED;
	else if (key == KEY_RIGHT)
		data->player_angle += ROTATION_SPEED;
}

int	padding_new_position(double new, double old)
{
	int		var;
	float	p;

	var = 0;
	p = 0.2;
	if (new > old)
		var = (int)(new + p);
	else
		var = (int)(new - p);
	return (var);
}

void	fix_dis(t_data *data)
{
	if (data->player_angle < 0)
		data->player_angle += 2 * PI;
	if (data->player_angle > 2 * PI)
		data->player_angle -= 2 * PI;
	data->new_map_x = padding_new_position(data->new_x, data->player_x);
	data->new_map_y = padding_new_position(data->new_y, data->player_y);
	data->old_map_x = (int)data->player_x;
	data->old_map_y = (int)data->player_y;
}

int	handle_keypress(int key, t_data *data)
{
	data->new_x = data->player_x;
	data->new_y = data->player_y;
	data->dir_x = cos(data->player_angle);
	data->dir_y = sin(data->player_angle);
	handel_moves(key, data);
	fix_dis(data);
	if (data->new_map_x >= 0 && data->new_map_x < data->map_width
		&& data->new_map_y >= 0 && data->new_map_y < data->map_height
		&& data->map[data->new_map_y][data->new_map_x] != '1')
	{
		if (data->map[data->old_map_y][data->new_map_x] != '1'
			&& data->map[data->new_map_y][data->old_map_x] != '1')
		{
			data->player_x = data->new_x;
			data->player_y = data->new_y;
		}
	}
	return (0);
}
