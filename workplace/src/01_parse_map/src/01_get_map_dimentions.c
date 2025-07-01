/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_get_map_dimentions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:16:21 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/01 13:09:13 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parse.h"

static int	get_columns_size(char *line)
{
	char	**elements;
	int		cols;
	int		i;

	elements = ft_split(line, ' ');
	if (!elements)
	{
		write(2, "Error: Memory allocation failed\n", 33);
		exit(1);
	}
	cols = 0;
	i = 0;
	while (elements[i])
	{
		cols++;
		i++;
	}
	ft_free_split(elements);
	return (cols);
}

static void	process_remaining_lines(int fd, int *rows, int cols)
{
	char	*line;
	int		current_cols;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		current_cols = get_columns_size(line);
		if (current_cols != cols)
		{
			free(line);
			close(fd);
			write(2, "Error: Inconsistent row length\n", 32);
			exit(1);
		}
		free(line);
		(*rows)++;
	}
}

static void	validate_and_count(int fd, int *rows, int *cols)
{
	char	*line;

	*rows = 0;
	*cols = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		write(2, "Error: Empty file\n", 18);
		exit(1);
	}
	*cols = get_columns_size(line);
	free(line);
	(*rows)++;
	process_remaining_lines(fd, rows, *cols);
}

void	get_map_dimentions(char *filename, int *rows, int *cols)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: Cannot open file\n", 25);
		exit(1);
	}
	validate_and_count(fd, rows, cols);
	close(fd);
	if (*rows <= 0 || *cols <= 0)
	{
		write(2, "Error: Invalid map dimensions\n", 31);
		exit(1);
	}
}
