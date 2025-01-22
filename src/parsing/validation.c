/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:57:13 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:12 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	check_pos(char **map, int y, int x)
{
	size_t	row_len;
	size_t	x_pos;

	if (!map || !map[y])
		return (1);
	row_len = ft_strlen(map[y]);
	x_pos = (size_t)x;
	if (y == 0 || !map[y - 1] || x_pos >= ft_strlen(map[y - 1])
		|| is_whitespace(map[y - 1][x]))
		return (1);
	if (!map[y + 1] || x_pos >= ft_strlen(map[y + 1])
		|| is_whitespace(map[y + 1][x]))
		return (1);
	if (x == 0 || is_whitespace(map[y][x - 1]))
		return (1);
	if (x_pos >= row_len - 1 || is_whitespace(map[y][x + 1]))
		return (1);
	return (0);
}

void	ft_check_new_map(t_data *data, t_var var)
{
	if (!var.new_map)
	{
		printf("Error\nMemory allocation failed\n");
		ft_free_data(data);
	}
}

void	check_wall_characters(t_data *data, char **map)
{
	t_var	var;

	var.i = 0;
	var.flag = 0;
	var.new_map = copy_map(map);
	ft_check_new_map(data, var);
	while (var.new_map[var.i])
	{
		var.j = 0;
		while (var.new_map[var.i][var.j])
		{
			if (ft_strsrch("0NSEW", var.new_map[var.i][var.j]))
				var.flag = check_pos(var.new_map, var.i, var.j);
			if (var.flag == 1)
			{
				free_str(var.new_map);
				printf("Error\nmap not close by wall\n");
				ft_free_data(data);
			}
			var.j++;
		}
		var.i++;
	}
	free_str(var.new_map);
}

void	check_position(t_data *data, char **map)
{
	int		i;
	int		j;
	size_t	cont;

	cont = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		if (cont < ft_strlen(map[i]))
			cont = ft_strlen(map[i]);
		while (map[i][j])
		{
			if (ft_strsrch("NSEW", map[i][j]))
			{
				data->player_x = j + 0.2;
				data->player_y = i + 0.2;
			}
			j++;
		}
		i++;
	}
	data->map_width = cont;
	data->map_height = i;
}
