/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/01 10:37:59 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if 0
int	main(void)
{
	void	*mlx;
	void	*win;
	int		count;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		printf("Initialization failed\n");
		return (1);
	}
	win = mlx_new_window(mlx, 200, 200, "Hello world!");
	count = 200;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			mlx_pixel_put(mlx, win, i, j, 0x00FFFFFF - i);
		}
	}
	mlx_string_put(mlx, win, 0, 0, 0x00FFFFFF, "42Tokyo");
	mlx_loop(mlx);
	return (0);
}

#endif

int	main(int argc, char *argv[])
{
	int		**map;
	int		rows;
	int		cols;
	t_fdf	*fdf;

	/* 入力検証 */
	input_validation(argc, argv);

	/* mapデータを解析 */
	if (parse_map(argv[1], &map, &rows, &cols) < 0)
	{
		write(2, "Error: Failed to parse map\n", 28);
		return (1);
	}

	/* グラフィック環境の初期化 */
	fdf = init_fdf(map, rows, cols);
	if (!fdf)
	{
		write(2, "Error: Failed to initialize graphics\n", 38);
		free_map(map, rows);
		return (1);
	}

	/* イメージシステムの初期化 */
	if (init_image(fdf) < 0)
	{
		write(2, "Error: Failed to initialize image\n", 35);
		cleanup_fdf(fdf);
		free_map(map, rows);
		return (1);
	}

	/* イベント設定 */
	setup_events(fdf);

	/* 投影パラメータの計算 */
	calculate_projection_params(fdf);

	/* マップを描画 */
	draw_map(fdf);

	/* メインループ */
	mlx_loop(fdf->mlx);

	return (0);
}
