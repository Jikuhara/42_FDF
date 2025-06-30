/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 17:55:26 by kei2003730       ###   ########.fr       */
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
	int	**map;
	int	rows;
	int	cols;
	int	i;
	int	j;

	input_validation(argc, argv);
	if (parse_map(argv[1], &map, &rows, &cols) < 0)
	{
		write(2, "Error: Failed to parse map\n", 28);
		return (1);
	}
	printf("Map size: %d x %d\n", rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%3d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_map(map, rows);
	return (0);
}
