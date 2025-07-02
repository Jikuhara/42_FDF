/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:23:39 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/02 15:46:07 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Forward declarations for internal functions */
void	get_map_dimentions(char *filename, int *rows, int *cols);
void	allocate_map_memory(int ***map, int rows, int cols);
void	fill_map_data(char *filename, int **map, int rows, int cols);

void	parse_map(char *filename, int ***map, int *rows, int *cols)
{
	get_map_dimentions(filename, rows, cols);
	allocate_map_memory(map, *rows, *cols);
	fill_map_data(filename, *map, *rows, *cols);
}
