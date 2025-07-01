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

void	calculate_projection_params(t_fdf *fdf)
{
	fdf->zoom = ZOOM_FACTOR;
	if (fdf->cols > 50 || fdf->rows > 50)
	{
		fdf->zoom = ZOOM_FACTOR / 2;
	}
	if (fdf->cols > 100 || fdf->rows > 100)
	{
		fdf->zoom = ZOOM_FACTOR / 4;
	}
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = WIN_HEIGHT / 2;
}
