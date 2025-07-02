/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:00:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/07/01 10:00:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = fdf->addr + (y * fdf->line_length + x * \
(fdf->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	clear_image(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(fdf, x, y, COLOR_BLACK);
			x++;
		}
		y++;
	}
}

t_point	create_3d_point(int x, int y, int z)
{
	t_point	point;

	point.x = (float)x;
	point.y = (float)y;
	point.z = (float)z;
	return (point);
}

void	cleanup_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->img)
		{
			mlx_destroy_image(fdf->mlx, fdf->img);
		}
		if (fdf->win)
		{
			mlx_destroy_window(fdf->mlx, fdf->win);
		}
		if (fdf->mlx)
		{
			mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		free(fdf);
	}
}

void	free_map(int **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
