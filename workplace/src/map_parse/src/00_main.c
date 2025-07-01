/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:23:39 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/01 13:09:13 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

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
