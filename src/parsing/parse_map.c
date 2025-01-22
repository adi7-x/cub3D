/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:57 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 18:33:33 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	**add_line(char **tokens, char *line)
{
	int		i;
	int		len;
	char	**new_tokens;

	i = 0;
	len = count_strings(tokens);
	new_tokens = malloc(sizeof(char *) * (len + 2));
	if (!new_tokens)
		handle_error("Error\nMalloc failed\n");
	while (tokens && tokens[i])
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	new_tokens[i] = ft_strdup(line);
	new_tokens[i + 1] = NULL;
	free(tokens);
	return (new_tokens);
}

void	ft_handle2(t_data *data, char **tokens, char **path)
{
	if (*path)
	{
		printf("Error\nDuplicate path\n");
		free_str(tokens);
		ft_free_data(data);
	}
}

void	add_to_path(t_data *data, char **path, char **tokens)
{
	int	fd;

	if (count_strings(tokens) != 2)
	{
		printf("Error\nInvalid path\n");
		free_str(tokens);
		free_str(data->token);
		ft_free_data(data);
	}
	ft_handle2(data, tokens, path);
	fd = 0;
	fd = open(tokens[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCouldn't open file\n");
		free_str(tokens);
		free_str(data->token);
		ft_free_data(data);
		close(fd);
	}
	*path = tokens[1];
	free(tokens[0]);
	free(tokens);
}

int	process_key_value(t_data *data, char *kv)
{
	char	**tokens;

	if (!ft_whitespace(kv))
	{
		return (0);
	}
	tokens = ft_split1(kv);
	if (!ft_strcmp("NO", tokens[0]))
		add_to_path(data, &data->no_texture, tokens);
	else if (!ft_strcmp("SO", tokens[0]))
		add_to_path(data, &data->so_texture, tokens);
	else if (!ft_strcmp("WE", tokens[0]))
		add_to_path(data, &data->we_texture, tokens);
	else if (!ft_strcmp("EA", tokens[0]))
		add_to_path(data, &data->ea_texture, tokens);
	else if (!ft_strcmp("F", tokens[0]))
		add_color(data, 2, tokens);
	else if (!ft_strcmp("C", tokens[0]))
		add_color(data, 1, tokens);
	else if (tokens[0][0] != '\n')
	{
		free_str(tokens);
		return (1);
	}
	return (0);
}

void	read_map(t_data *data, char **tokens)
{
	int	i;

	i = 0;
	data->ceiling_color = -1;
	data->floor_color = -1;
	while (tokens[i])
	{
		if (process_key_value(data, tokens[i]))
			break ;
		i++;
	}
	while (tokens[i])
	{
		data->map = add_line(data->map, tokens[i]);
		i++;
	}
	free_str(data->token);
}
