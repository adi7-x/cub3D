/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:24 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:19:31 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	init_data(t_data *data)
{
	data->res_x = -1;
	data->res_y = -1;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->player_x = -1;
	data->player_y = -1;
	data->player_dir = -1;
	data->has_no = 0;
	data->has_so = 0;
	data->has_we = 0;
	data->has_ea = 0;
	data->has_floor = 0;
	data->has_ceiling = 0;
	data->has_sprite = 0;
	return (0);
}
