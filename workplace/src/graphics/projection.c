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

/* アイソメトリック投影を使って3D座標を2D画面座標に変換 */
t_screen_point	project_point(t_point point3d, t_fdf *fdf)
{
	t_screen_point	screen_point;
	float			iso_x;
	float			iso_y;

	/* アイソメトリック投影の計算 */
	iso_x = (point3d.x - point3d.y) * cos(ISO_ANGLE);
	iso_y = (point3d.x + point3d.y) * sin(ISO_ANGLE) - point3d.z;

	/* ズームと画面中央への配置調整 */
	screen_point.x = (int)(iso_x * fdf->zoom) + fdf->offset_x;
	screen_point.y = (int)(iso_y * fdf->zoom) + fdf->offset_y;

	/* 高度に応じた色の計算（簡単なグラデーション） */
	if (point3d.z == 0)
		screen_point.color = COLOR_WHITE;
	else if (point3d.z > 0)
		screen_point.color = COLOR_RED;
	else
		screen_point.color = COLOR_BLUE;

	return (screen_point);
}

/* 投影パラメータの計算（ズームと中央配置のための調整） */
void	calculate_projection_params(t_fdf *fdf)
{
	/* 基本ズーム値の設定 */
	fdf->zoom = ZOOM_FACTOR;

	/* マップサイズに応じたズーム調整 */
	if (fdf->cols > 50 || fdf->rows > 50)
		fdf->zoom = ZOOM_FACTOR / 2;
	if (fdf->cols > 100 || fdf->rows > 100)
		fdf->zoom = ZOOM_FACTOR / 4;

	/* 画面中央への配置調整 */
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = WIN_HEIGHT / 2;
}

/* マップ全体を描画 */
void	draw_map(t_fdf *fdf)
{
	int				x;
	int				y;
	t_point			point3d;
	t_screen_point	screen_point;

	/* 画面をクリア */
	clear_image(fdf);

	/* 各点を描画 */
	y = 0;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			/* 3D座標を作成 */
			point3d = create_3d_point(x, y, fdf->map[y][x]);

			/* 2D画面座標に投影 */
			screen_point = project_point(point3d, fdf);

			/* ピクセルを描画（画面内の場合のみ） */
			if (screen_point.x >= 0 && screen_point.x < WIN_WIDTH &&
				screen_point.y >= 0 && screen_point.y < WIN_HEIGHT)
				my_mlx_pixel_put(fdf, screen_point.x, screen_point.y, screen_point.color);

			x++;
		}
		y++;
	}

	/* 画面に表示 */
	render_to_window(fdf);
}
