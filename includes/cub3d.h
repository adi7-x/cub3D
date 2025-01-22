/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:00 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 23:56:42 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d.h"
# include "includes/defines.h"
# include "includes/structs.h"
# include <mlx.h>
# include "libft.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		close_window(t_data *data);

char	**ft_skip_empty_lines(char **map);
void	check_position(t_data *data, char **map);
void	check_wall_characters(t_data *data, char **map);
void	check_path_extension(t_data *data);
char	**ft_split1(char *str);
void	read_map(t_data *data, char **tokens);
char	*ft_strsrch(char *str, char c);

char	**add_line(char **tokens, char *line);

int		init_data(t_data *data);
int		parse_file(char *file, t_data *data);
int		validate_file_extension(const char *filename);
int		process_key_value(t_data *data, char *kv);

char	*get_next_line(int fd);
size_t	ft_strlen_get(char *s);
char	*ft_strdup_get(char *s1);
char	*ft_strjoin_get(char *remainder1, char *buffer1);
char	*ft_strchr_get(const char *s, int c);
void	handle_error(char *message);

int		validate_rgb_format(const char *str);

int		ft_strcmp(const char *s1, const char *s2);
char	**copy_map(char **map);
char	**ft_copy_map(char **map);
int		count_strings(char **map);
void	ft_free_data(t_data *data);
void	read_file(char *file, t_data *data);
int		is_whitespace(char c);
int		ft_whitespace(const char *str);
void	check_characters(t_data *data, char **map);
void	free_str(char **str);
void	handel_x(t_data *data);
void	handel_y(t_data *data);
void	handel_tex(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_texture_color(t_texture *tex, int x, int y);
void	calculate_dest(t_data *data);
void	dda(t_data *data);
void	draw_direction_line(t_data *data);
void	int_rays(t_data *data);
void	handel_moves(int key, t_data *data);
int		padding_new_position(double new, double old);
int		handle_keypress(int key, t_data *data);
void	load_texture(t_data *data, t_texture *tex, char *path);
void	load_all_textures(t_data *data);
void	free_all_images(t_data *data);
void	add_color(t_data *data, int type, char **tokens);
#endif