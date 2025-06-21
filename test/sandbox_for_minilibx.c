/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox_for_minilibx.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:00:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2025/06/21 21:39:23 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../minilibx-linux/mlx.h"

int main(int argc, char const *argv[])
{
	void *mlx_ptr = mlx_init();
	printf("%p\n", mlx_ptr);
	void *mlx_success = mlx_new_window(mlx_ptr, 100, 100, "test_title");
	printf("%p\n", mlx_success);
	return (0);
}
