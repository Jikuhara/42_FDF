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

int	key_press(int keycode, t_fdf *fdf);
int	mouse_hook(int button, int x, int y, t_fdf *fdf);

static int	close_window(t_fdf *fdf)
{
	cleanup_fdf(fdf);
	exit(0);
	return (0);
}

void	setup_events(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_hook(fdf->win, X11_EVENT_DESTROY_NOTIFY, 0, close_window, fdf);
}
