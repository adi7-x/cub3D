/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:56:15 by adbourji          #+#    #+#             */
/*   Updated: 2025/01/22 15:56:16 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (!data || !data->img_data)
		return ;
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = y * data->size_line + x * (data->bpp / 8);
	if (pixel < 0 || pixel >= (WINDOW_HEIGHT * data->size_line))
		return ;
	*(int *)(data->img_data + pixel) = color;
}

int	get_texture_color(t_texture *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_length + x * (tex->bpp / 8));
	return (*(int *)dst);
}
