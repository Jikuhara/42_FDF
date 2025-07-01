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

static void	find_min_max_z(t_fdf *fdf, int *min_z, int *max_z)
{
	int	x;
	int	y;

	*min_z = fdf->map[0][0];
	*max_z = fdf->map[0][0];
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			if (fdf->map[y][x] < *min_z)
				*min_z = fdf->map[y][x];
			if (fdf->map[y][x] > *max_z)
				*max_z = fdf->map[y][x];
			x++;
		}
		y++;
	}
}

static t_screen_point	get_screen_point(t_fdf *fdf, int x, int y,
										int min_z, int max_z)
{
	t_point			point3d;
	t_screen_point	screen_point;

	point3d = create_3d_point(x, y, fdf->map[y][x]);
	screen_point = project_point(point3d, fdf);
	screen_point.color = get_color_by_height(fdf->map[y][x], min_z, max_z);
	return (screen_point);
}

static void	draw_horizontal_lines(t_fdf *fdf, int min_z, int max_z)
{
	int				x;
	int				y;
	t_screen_point	current;
	t_screen_point	next;

	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols - 1)
		{
			current = get_screen_point(fdf, x, y, min_z, max_z);
			next = get_screen_point(fdf, x + 1, y, min_z, max_z);
			draw_line(fdf, current, next);
			x++;
		}
		y++;
	}
}

static void	draw_vertical_lines(t_fdf *fdf, int min_z, int max_z)
{
	int				x;
	int				y;
	t_screen_point	current;
	t_screen_point	next;

	x = 0;
	while (x < fdf->cols)
	{
		y = 0;
		while (y < fdf->rows - 1)
		{
			current = get_screen_point(fdf, x, y, min_z, max_z);
			next = get_screen_point(fdf, x, y + 1, min_z, max_z);
			draw_line(fdf, current, next);
			y++;
		}
		x++;
	}
}
