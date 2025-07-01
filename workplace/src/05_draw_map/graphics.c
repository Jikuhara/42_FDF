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

t_screen_point	project_point(t_point point3d, t_fdf *fdf)
{
	t_screen_point	screen_point;
	float			iso_x;
	float			iso_y;

	iso_x = (point3d.x - point3d.y) * cos(ISO_ANGLE);
	iso_y = (point3d.x + point3d.y) * sin(ISO_ANGLE) - point3d.z;
	screen_point.x = (int)(iso_x * fdf->zoom) + fdf->offset_x;
	screen_point.y = (int)(iso_y * fdf->zoom) + fdf->offset_y;
	if (point3d.z == 0)
		screen_point.color = COLOR_WHITE;
	else if (point3d.z > 0)
		screen_point.color = COLOR_RED;
	else
		screen_point.color = COLOR_BLUE;
	return (screen_point);
}
