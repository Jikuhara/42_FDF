/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:00:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/07/01 10:00:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	redraw_map(t_fdf *fdf)
{
	clear_image(fdf);
	draw_map(fdf);
	render_to_window(fdf);
}

static void	zoom_in(t_fdf *fdf)
{
	if (fdf->zoom < 100)
	{
		fdf->zoom += 2;
		redraw_map(fdf);
	}
}

static void	zoom_out(t_fdf *fdf)
{
	if (fdf->zoom > 2)
	{
		fdf->zoom -= 2;
		redraw_map(fdf);
	}
}

int	mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_UP)
		zoom_in(fdf);
	else if (button == MOUSE_WHEEL_DOWN)
		zoom_out(fdf);
	return (0);
}
