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

void	render_to_window(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
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
