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

#include "map_parse.h"

static int	process_line_data(char *line, int **map, int row, int cols)
{
	char	**elements;
	int		j;

	elements = ft_split(line, ' ');
	if (!elements)
		return (-1);
	j = 0;
	while (elements[j] && j < cols)
	{
		map[row][j] = ft_atoi(elements[j]);
		j++;
	}
	ft_free_split(elements);
	return (0);
}

static void	read_and_process_lines(int fd, int **map, int rows, int cols)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < rows)
	{
		if (process_line_data(line, map, i, cols) == -1)
		{
			free(line);
			close(fd);
			write(2, "Error: Memory allocation failed\n", 33);
			exit(1);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
}

void	fill_map_data(char *filename, int **map, int rows, int cols)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: Cannot open file\n", 25);
		exit(1);
	}
	read_and_process_lines(fd, map, rows, cols);
	close(fd);
}
