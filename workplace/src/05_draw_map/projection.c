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

void	find_min_max_z(t_fdf *fdf, int *min_z, int *max_z)
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

t_screen_point	get_screen_point(t_fdf *fdf, int x, int y, t_z_range z_range)
{
	t_point			point3d;
	t_screen_point	screen_point;

	point3d = create_3d_point(x, y, fdf->map[y][x]);
	screen_point = project_point(point3d, fdf);
	screen_point.color = get_color_by_height(fdf->map[y][x], z_range.min_z,
			z_range.max_z);
	return (screen_point);
}

void	draw_horizontal_lines(t_fdf *fdf, int min_z, int max_z)
{
	int				x;
	int				y;
	t_screen_point	current;
	t_screen_point	next;
	t_z_range		z_range;

	z_range.min_z = min_z;
	z_range.max_z = max_z;
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols - 1)
		{
			current = get_screen_point(fdf, x, y, z_range);
			next = get_screen_point(fdf, x + 1, y, z_range);
			draw_line(fdf, current, next);
			x++;
		}
		y++;
	}
}

void	draw_vertical_lines(t_fdf *fdf, int min_z, int max_z)
{
	int				x;
	int				y;
	t_screen_point	current;
	t_screen_point	next;
	t_z_range		z_range;

	z_range.min_z = min_z;
	z_range.max_z = max_z;
	x = 0;
	while (x < fdf->cols)
	{
		y = 0;
		while (y < fdf->rows - 1)
		{
			current = get_screen_point(fdf, x, y, z_range);
			next = get_screen_point(fdf, x, y + 1, z_range);
			draw_line(fdf, current, next);
			y++;
		}
		x++;
	}
}
