/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 15:12:16 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
