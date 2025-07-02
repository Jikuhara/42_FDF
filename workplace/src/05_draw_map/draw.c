/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:00:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/07/01 14:00:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color_by_height(int z, int min_z, int max_z)
{
	float	ratio;
	int		red;
	int		green;
	int		blue;

	if (max_z == min_z)
		return (COLOR_WHITE);
	ratio = (float)(z - min_z) / (max_z - min_z);
	if (ratio < 0.5)
	{
		blue = (int)(255 * (1 - ratio * 2));
		green = (int)(255 * (ratio * 2));
		red = 0;
	}
	else
	{
		blue = 0;
		green = (int)(255 * (1 - (ratio - 0.5) * 2));
		red = (int)(255 * ((ratio - 0.5) * 2));
	}
	return ((red << 16) | (green << 8) | blue);
}

int	interpolate_color(int color1, int color2, float ratio)
{
	int	r;
	int	g;
	int	b;

	r = (color1 >> 16 & 0xFF) + ((color2 >> 16 & 0xFF) - (color1 >> 16 & 0xFF))
		* ratio;
	g = (color1 >> 8 & 0xFF) + ((color2 >> 8 & 0xFF) - (color1 >> 8 & 0xFF))
		* ratio;
	b = (color1 & 0xFF) + ((color2 & 0xFF) - (color1 & 0xFF)) * ratio;
	return ((r << 16) | (g << 8) | b);
}

void	draw_line_pixels(t_fdf *fdf, t_screen_point p1, t_screen_point p2,
		int steps)
{
	float	x;
	float	y;
	float	x_inc;
	float	y_inc;
	int		i;

	x_inc = (float)(p2.x - p1.x) / steps;
	y_inc = (float)(p2.y - p1.y) / steps;
	x = p1.x;
	y = p1.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(fdf, (int)x, (int)y, interpolate_color(p1.color,
				p2.color, (float)i / steps));
		x += x_inc;
		y += y_inc;
		i++;
	}
}

// 呼び出し側
void	draw_line(t_fdf *fdf, t_screen_point p1, t_screen_point p2)
{
	int	dx;
	int	dy;
	int	steps;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	ft_max_int(ft_abs_int(dx), ft_abs_int(dy), &steps);
	draw_line_pixels(fdf, p1, p2, steps);
}
