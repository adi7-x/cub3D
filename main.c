/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:13 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 16:05:54 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	draw_map(t_data *data)
{
	draw_direction_line(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int	close_window(t_data *data)
{
	if (!data)
		return (0);
	free_all_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->map)
		free_str(data->map);
	exit(0);
	return (0);
}

int	handle_esc(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

void	check_angle(t_data *data)
{
	if (data->map[(int)data->player_y][(int)data->player_x] == 'N')
		data->player_angle = 0;
	if (data->map[(int)data->player_y][(int)data->player_x] == 'S')
		data->player_angle = 180 * (PI / 180);
	if (data->map[(int)data->player_y][(int)data->player_x] == 'E')
		data->player_angle = 90 * (PI / 180);
	if (data->map[(int)data->player_y][(int)data->player_x] == 'W')
		data->player_angle = 270 * (PI / 180);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		handle_error("Error\nUsage: ./cub3d map.cub\n");
	if (!validate_file_extension(argv[1]))
		handle_error("Error\nInvalid file extension\n");
	init_data(&data);
	parse_file(argv[1], &data);
	check_angle(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	load_all_textures(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!data.win)
		return (1);
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img_data = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,
			&data.endian);
	mlx_hook(data.win, 2, 1, handle_keypress, &data);
	mlx_loop_hook(data.mlx, draw_map, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, handle_esc, &data);
	mlx_loop(data.mlx);
	return (0);
}
