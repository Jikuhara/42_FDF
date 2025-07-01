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

int	close_program(t_fdf *fdf)
{
	cleanup_fdf(fdf);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		close_program(fdf);
	else if (keycode == PLUS_KEY || keycode == NUM_PLUS_KEY)
		zoom_in(fdf);
	else if (keycode == MINUS_KEY || keycode == NUM_MINUS_KEY)
		zoom_out(fdf);
	return (0);
}

int	close_window(t_fdf *fdf)
{
	close_program(fdf);
	return (0);
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

void	setup_events(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}
