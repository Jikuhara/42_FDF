/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:22 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/01 15:10:24 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_graphics(t_fdf **fdf, int **map, int rows, int cols)
{
	*fdf = init_fdf(map, rows, cols);
	if (!*fdf)
	{
		write(2, "Error: Failed to initialize graphics\n", 38);
		free_map(map, rows);
		exit(1);
	}
	if (init_image(*fdf) < 0)
	{
		write(2, "Error: Failed to initialize image\n", 35);
		cleanup_fdf(*fdf);
		free_map(map, rows);
		exit(1);
	}
}
