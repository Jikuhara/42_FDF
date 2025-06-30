/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 15:41:02 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	is_fdf_extention(char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || ft_strcmp(dot, ".fdf") != 0)
		return (0);
	return (1);
}

void	input_validation(int argc, char *argv[])
{
	int fd;
	if (argc != 2)
		return ;
	if (is_fdf_extexntion(argv[1]))
		return ;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	return ;
}
