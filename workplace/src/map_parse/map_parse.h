/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:00:00 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/01 13:07:20 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSE_H
# define MAP_PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* Public API - Only these functions are visible from outside */
void	parse_map(char *filename, int ***map, int *rows, int *cols);
void	free_map(int **map, int rows);

/* Required external functions (should be provided by user) */
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);
int		ft_atoi(const char *str);

#endif
