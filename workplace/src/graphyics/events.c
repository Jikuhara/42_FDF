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

/* プログラム終了処理 */
int	close_program(t_fdf *fdf)
{
	cleanup_fdf(fdf);
	exit(0);
	return (0);
}

/* キーイベント処理 */
int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		close_program(fdf);
	return (0);
}

/* ×ボタンクリック処理 */
int	close_window(t_fdf *fdf)
{
	close_program(fdf);
	return (0);
}

/* イベントハンドラーの設定 */
void	setup_events(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}
