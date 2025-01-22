/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:37 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 19:34:01 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_free_data(t_data *data)
{
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
	exit(1);
}

int	validate_rgb_format(const char *str)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i])
	{
		if (str[i] == ',')
			commas++;
		else if (!ft_isdigit(str[i]) && str[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (commas == 2);
}

int	convert_rgb_to_int(t_data *data, char **rgb, char **tokens)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		printf("Error\nInvalid color value\n");
		free_str(tokens);
		free_str(rgb);
		free_str(data->token);
		ft_free_data(data);
	}
	ft_memset(&color, r, 3);
	ft_memset(&color, g, 2);
	ft_memset(&color, b, 1);
	return (color);
}

void	ft_handle_color(t_data *data, int i, char **rgb, char **tokens)
{
	if (i != 3 || !validate_rgb_format(tokens[1]))
	{
		printf("Error\nInvalid color format\n");
		free_str(tokens);
		free_str(rgb);
		free_str(data->token);
		ft_free_data(data);
	}
}

void	add_color(t_data *data, int type, char **tokens)
{
	int		color;
	char	**rgb;
	int		i;

	if (count_strings(tokens) != 2)
	{
		printf("Error\nInvalid color value\n");
		free_str(tokens);
		free_str(data->token);
		ft_free_data(data);
	}
	rgb = ft_split(tokens[1], ',');
	i = 0;
	while (rgb[i])
		i++;
	ft_handle_color(data, i, rgb, tokens);
	color = convert_rgb_to_int(data, rgb, tokens);
	if (type == 1)
		data->ceiling_color = color;
	else
		data->floor_color = color;
	free_str(tokens);
	free_str(rgb);
}
