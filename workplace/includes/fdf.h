/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/01 10:37:59 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

/* キーコード定義 */
# define ESC_KEY 65307

/* 色定義 */
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_BLACK 0x000000

/* ウィンドウサイズ */
# define WIN_WIDTH 1000
# define WIN_HEIGHT 700

/* 座標変換のためのパラメータ */
# define ZOOM_FACTOR 20
# define ISO_ANGLE 0.523599  /* 30度をラジアンで */

/* 3D座標を表す構造体 */
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

/* 2D画面座標を表す構造体 */
typedef struct s_screen_point
{
	int	x;
	int	y;
	int	color;
}	t_screen_point;

/* FDF構造体 */
typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		**map;
	int		rows;
	int		cols;
	int		zoom;
	int		offset_x;
	int		offset_y;
}	t_fdf;

/* input_validation.c */
void	input_validation(int argc, char *argv[]);

/* map_parser.c */
int		parse_map(char *filename, int ***map, int *rows, int *cols);
void	free_map(int **map, int rows);
void	free_split(char **split);

/* graphics.c */
t_fdf	*init_fdf(int **map, int rows, int cols);
int		init_image(t_fdf *fdf);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void	clear_image(t_fdf *fdf);
void	render_to_window(t_fdf *fdf);
void	cleanup_fdf(t_fdf *fdf);

/* events.c */
int		close_program(t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	setup_events(t_fdf *fdf);

/* projection.c */
t_screen_point	project_point(t_point point3d, t_fdf *fdf);
t_point		create_3d_point(int x, int y, int z);
void		calculate_projection_params(t_fdf *fdf);
void		draw_map(t_fdf *fdf);

/* get_next_line関数が必要 */
char	*get_next_line(int fd);

#endif
