/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 17:36:39 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_fdf_extention(char *filename)
{
	return (ft_strrcmp(filename, ".fdf") == 0);
}

void	input_validation(int argc, char *argv[])
{
	int fd;
	if (argc != 2)
		return ;
	if (!is_fdf_extention(argv[1]))
		return ;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
	return ;
}
