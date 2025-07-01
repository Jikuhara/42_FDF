/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/07/01 16:26:36 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC_KEY 65307
# define PLUS_KEY 61
# define MINUS_KEY 45
# define NUM_PLUS_KEY 65451
# define NUM_MINUS_KEY 65453
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF
# define COLOR_BLACK 0x000000

# define WIN_WIDTH 1000
# define WIN_HEIGHT 700

# define ZOOM_FACTOR 20
# define ISO_ANGLE 0.523599

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct s_screen_point
{
	int			x;
	int			y;
	int			color;
}				t_screen_point;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			**map;
	int			rows;
	int			cols;
	int			zoom;
	int			offset_x;
	int			offset_y;
}				t_fdf;

/* input_validation.c */
void			input_validation(int argc, char *argv[]);

/* map_parser.c */
void			parse_map(char *filename, int ***map, int *rows, int *cols);
void			free_map(int **map, int rows);

/* get_map_dimentions.c */
void			get_map_dimentions(char *filename, int *rows, int *cols);

/* graphics.c */
t_fdf			*init_fdf(int **map, int rows, int cols);
int				init_image(t_fdf *fdf);
void			my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void			clear_image(t_fdf *fdf);
void			render_to_window(t_fdf *fdf);
void			cleanup_fdf(t_fdf *fdf);
void			initialize_graphics(t_fdf **fdf, int **map, int rows, int cols);

/* draw.c */
int				get_color_by_height(int z, int min_z, int max_z);
int				interpolate_color(int color1, int color2, float ratio);
void			draw_line(t_fdf *fdf, t_screen_point p1, t_screen_point p2);
void			draw_line_pixels(t_fdf *fdf, t_screen_point p1,
				t_screen_point p2, float x_inc, float y_inc);

/* events.c */
int				close_program(t_fdf *fdf);
int				key_press(int keycode, t_fdf *fdf);
int				close_window(t_fdf *fdf);
int				mouse_hook(int button, int x, int y, t_fdf *fdf);
void			setup_events(t_fdf *fdf);

/* projection.c */
t_screen_point	project_point(t_point point3d, t_fdf *fdf);
t_point			create_3d_point(int x, int y, int z);
void			calculate_projection_params(t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			find_min_max_z(t_fdf *fdf, int *min_z, int *max_z);
t_screen_point	get_screen_point(t_fdf *fdf, int x, int y, int min_z, int max_z);
void			draw_horizontal_lines(t_fdf *fdf, int min_z, int max_z);
void			draw_vertical_lines(t_fdf *fdf, int min_z, int max_z);

#endif
