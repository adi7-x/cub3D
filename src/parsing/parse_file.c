/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:41 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 21:22:41 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	validate_file_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (!ft_strcmp(filename + len - 4, ".cub"));
}

void	read_file(char *file, t_data *data)
{
	char	**tokens;
	char	*line;
	int		fd;

	tokens = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error("Error\nCouldn't open file\n");
	line = get_next_line(fd);
	if (line == NULL)
	{
		handle_error("Error\nEmpty file\n");
		exit(1);
	}
	line[ft_strlen(line) - 1] = '\0';
	while (line)
	{
		tokens = add_line(tokens, line);
		free(line);
		line = get_next_line(fd);
		if (line)
			line[ft_strlen(line) - 1] = '\0';
	}
	data->token = tokens;
	read_map(data, tokens);
}

void	check_characters(t_data *data, char **map)
{
	t_var	var;

	var.i = 0;
	var.n = 0;
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (!ft_strsrch("\t01NSEW ", map[var.i][var.j]))
			{
				printf("Error\nyou can just Use (01NSEW) in map\n");
				ft_free_data(data);
			}
			if (ft_strsrch("NSEW", map[var.i][var.j]))
				var.n++;
			var.j++;
		}
		var.i++;
	}
	if (var.n != 1)
	{
		printf("Error\n please one plyer\n");
		ft_free_data(data);
	}
}

char	**ft_skip_empty_lines(char **map)
{
	int		i;
	int		len;
	char	**new_map;

	i = 0;
	len = count_strings(map);
	while (len)
	{
		if (ft_whitespace(map[len]))
			break ;
		free(map[len]);
		len--;
	}
	new_map = malloc(sizeof(char *) * (len + 2));
	if (!new_map)
		handle_error("Error\nMalloc failed\n");
	while (i <= len)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = NULL;
	free(map);
	return (new_map);
}

int	parse_file(char *file, t_data *data)
{
	read_file(file, data);
	check_path_extension(data);
	data->map = ft_skip_empty_lines(data->map);
	check_characters(data, data->map);
	check_wall_characters(data, data->map);
	check_position(data, data->map);
	return (0);
}
