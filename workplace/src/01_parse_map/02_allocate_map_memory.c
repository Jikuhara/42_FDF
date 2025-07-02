/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:00:00 by kei2003730       #+#    #+#             */
/*   Updated: 2025/06/30 18:00:00 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_map_memory(int ***map, int rows, int cols)
{
	int	i;

	*map = (int **)malloc(sizeof(int *) * rows);
	if (!*map)
	{
		write(2, "Error: Memory allocation failed\n", 33);
		exit(1);
	}
	i = 0;
	while (i < rows)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * cols);
		if (!(*map)[i])
		{
			while (--i >= 0)
				free((*map)[i]);
			free(*map);
			write(2, "Error: Memory allocation failed\n", 33);
			exit(1);
		}
		i++;
	}
}
