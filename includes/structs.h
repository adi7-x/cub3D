/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:26 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 15:55:27 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_data
{
	int			fd;
	char		**token;
	char		*line;
	int			res_x;
	int			res_y;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_dir;
	int			has_no;
	int			has_so;
	int			has_we;
	int			has_ea;
	int			has_floor;
	int			has_ceiling;
	int			has_sprite;

	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	float		player_x;

	int			new_map_x;
	int			new_map_y;
	int			old_map_x;
	int			old_map_y;
	float		player_y;
	float		player_angle;
	float		dir_x;
	float		dir_y;
	double		wall_height;
	int			color;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			start;
	int			end;
	int			i;
	float		current_angle;
	int			ray_num;
	float		new_des;
	float		ray_dir_x;
	float		ray_dir_y;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	float		new_x;
	float		new_y;
	float		distance;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}				t_data;

typedef struct s_key_value
{
	char		*key;
	char		*value;
}				t_key_value;

typedef struct t_var
{
	int			i;
	int			j;
	int			n;
	int			flag;
	char		**new_map;
}				t_var;

#endif