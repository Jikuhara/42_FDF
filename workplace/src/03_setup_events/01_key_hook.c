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

static void	move_left(t_fdf *fdf)
{
	fdf->offset_x -= 10;
	redraw_map(fdf);
}

static void	move_right(t_fdf *fdf)
{
	fdf->offset_x += 10;
	redraw_map(fdf);
}

static void	move_up(t_fdf *fdf)
{
	fdf->offset_y -= 10;
	redraw_map(fdf);
}

static void	move_down(t_fdf *fdf)
{
	fdf->offset_y += 10;
	redraw_map(fdf);
}

static int	close_program(t_fdf *fdf)
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
	else if (keycode == LEFT_ARROW)
		move_left(fdf);
	else if (keycode == RIGHT_ARROW)
		move_right(fdf);
	else if (keycode == UP_ARROW)
		move_up(fdf);
	else if (keycode == DOWN_ARROW)
		move_down(fdf);
	return (0);
}
