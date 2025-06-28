/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox_for_minilibx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/28 22:33:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>

int	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		printf("Initialization failed\n");
		return (1);
	}
	win = mlx_new_window(mlx, 200, 200, "Hello world!");
	int count = 200;
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
