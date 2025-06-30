/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 17:59:25 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_fdf_extention(char *filename)
{
	return (ft_strrcmp(filename, ".fdf") == 0);
}

void	input_validation(int argc, char *argv[])
{
	int	fd;
	int	**map;
	int	rows;
	int	cols;
	int	i;
	int	j;

	if (argc != 2)
		return ;
	if (!is_fdf_extention(argv[1]))
		return ;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	input_validation(argc, argv);
	if (parse_map(argv[1], &map, &rows, &cols) < 0)
	{
		write(2, "Error: Failed to parse map\n", 28);
		return (1);
	}
	printf("Map size: %d x %d\n", rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%3d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_map(map, rows);
	return (0);
}
