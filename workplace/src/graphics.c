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

/* グラフィック環境の初期化 */
t_fdf	*init_fdf(int **map, int rows, int cols)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = map;
	fdf->rows = rows;
	fdf->cols = cols;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free(fdf);
		return (NULL);
	}
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF - 42");
	if (!fdf->win)
	{
		free(fdf);
		return (NULL);
	}
	return (fdf);
}

/* イメージの初期化 */
int	init_image(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		return (-1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
		&fdf->line_length, &fdf->endian);
	if (!fdf->addr)
		return (-1);
	return (0);
}

/* イメージにピクセルを描画 */
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

/* イメージをクリア（黒で塗りつぶし） */
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

/* 画面にイメージを描画 */
void	render_to_window(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

/* リソースの解放 */
void	cleanup_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		if (fdf->mlx)
		{
			mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		free(fdf);
	}
}
