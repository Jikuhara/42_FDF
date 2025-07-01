/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/30 18:06:47 by kei2003730       ###   ########.fr       */
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

	if (argc != 2)
	{
		write(2, "Usage: ./fdf <filename>.fdf\n", 29);
		exit(1);
	}
	if (!is_fdf_extention(argv[1]))
	{
		write(2, "Error: File must have .fdf extension\n", 38);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: Cannot open file\n", 25);
		exit(1);
	}
	close(fd);
	return;
}
