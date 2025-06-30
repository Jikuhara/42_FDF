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

static int	get_map_dimensions(char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;
	char	**elements;
	int		temp_cols;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	*rows = 0;
	*cols = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		elements = ft_split(line, ' ');
		if (!elements)
		{
			free(line);
			close(fd);
			return (-1);
		}
		temp_cols = 0;
		while (elements[temp_cols])
			temp_cols++;
		if (*rows == 0)
			*cols = temp_cols;
		else if (*cols != temp_cols)
		{
			free_split(elements);
			free(line);
			close(fd);
			return (-1);
		}
		free_split(elements);
		free(line);
		(*rows)++;
	}
	close(fd);
	return (0);
}

static int	fill_map_data(char *filename, int **map, int rows, int cols)
{
	int		fd;
	char	*line;
	char	**elements;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while ((line = get_next_line(fd)) != NULL && i < rows)
	{
		elements = ft_split(line, ' ');
		if (!elements)
		{
			free(line);
			close(fd);
			return (-1);
		}
		j = 0;
		while (elements[j] && j < cols)
		{
			map[i][j] = ft_atoi(elements[j]);
			j++;
		}
		free_split(elements);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

static int	allocate_map_memory(int ***map, int rows, int cols)
{
	int	i;

	*map = (int **)malloc(sizeof(int *) * rows);
	if (!*map)
		return (-1);
	i = 0;
	while (i < rows)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * cols);
		if (!(*map)[i])
		{
			while (--i >= 0)
				free((*map)[i]);
			free(*map);
			*map = NULL;
			return (-1);
		}
		i++;
	}
	return (0);
}

void	free_map(int **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_map(char *filename, int ***map, int *rows, int *cols)
{
	if (get_map_dimensions(filename, rows, cols) < 0)
		return (-1);
	if (*rows <= 0 || *cols <= 0)
		return (-1);
	if (allocate_map_memory(map, *rows, *cols) < 0)
		return (-1);
	if (fill_map_data(filename, *map, *rows, *cols) < 0)
	{
		free_map(*map, *rows);
		*map = NULL;
		return (-1);
	}
	return (0);
}
