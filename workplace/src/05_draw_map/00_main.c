/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:30:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/07/01 10:30:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	min_z;
	int	max_z;

	clear_image(fdf);
	find_min_max_z(fdf, &min_z, &max_z);
	draw_horizontal_lines(fdf, min_z, max_z);
	draw_vertical_lines(fdf, min_z, max_z);
	render_to_window(fdf);
}
