/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:30:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/07/01 10:30:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 3D座標を作成 */
t_point	create_3d_point(int x, int y, int z)
{
	t_point	point;

	point.x = (float)x;
	point.y = (float)y;
	point.z = (float)z;
	return (point);
}

t_screen_point	project_point(t_point point3d, t_fdf *fdf)
{
	t_screen_point	screen_point;
	float			iso_x;
	float			iso_y;

	iso_x = (point3d.x - point3d.y) * cos(ISO_ANGLE);
	iso_y = (point3d.x + point3d.y) * sin(ISO_ANGLE) - point3d.z;
	screen_point.x = (int)(iso_x * fdf->zoom) + fdf->offset_x;
	screen_point.y = (int)(iso_y * fdf->zoom) + fdf->offset_y;
	if (point3d.z == 0)
		screen_point.color = COLOR_WHITE;
	else if (point3d.z > 0)
		screen_point.color = COLOR_RED;
	else
		screen_point.color = COLOR_BLUE;
	return (screen_point);
}

void	calculate_projection_params(t_fdf *fdf)
{
	fdf->zoom = ZOOM_FACTOR;
	if (fdf->cols > 50 || fdf->rows > 50)
	{
		fdf->zoom = ZOOM_FACTOR / 2;
	}
	if (fdf->cols > 100 || fdf->rows > 100)
	{
		fdf->zoom = ZOOM_FACTOR / 4;
	}
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = WIN_HEIGHT / 2;
}

static void	draw_single_point(t_fdf *fdf, int x, int y)
{
	t_point			point3d;
	t_screen_point	screen_point;

	point3d = create_3d_point(x, y, fdf->map[y][x]);
	screen_point = project_point(point3d, fdf);
	if (screen_point.x >= 0 && screen_point.x < WIN_WIDTH &&
		screen_point.y >= 0 && screen_point.y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(fdf, screen_point.x, screen_point.y,
			screen_point.color);
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf);
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			draw_single_point(fdf, x, y);
			x++;
		}
		y++;
	}
	render_to_window(fdf);
}
