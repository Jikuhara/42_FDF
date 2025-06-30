/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 17:47:11 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/* input_validation.c */
void	input_validation(int argc, char *argv[]);

/* map_parser.c */
int		parse_map(char *filename, int ***map, int *rows, int *cols);
void	free_map(int **map, int rows);
void	free_split(char **split);

/* get_next_line関数が必要 */
char	*get_next_line(int fd);

#endif
