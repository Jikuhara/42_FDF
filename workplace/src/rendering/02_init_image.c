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

int	init_image(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
	{
		return (-1);
	}
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
&fdf->line_length, &fdf->endian);
	if (!fdf->addr)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
		return (-1);
	}
	return (0);
}
