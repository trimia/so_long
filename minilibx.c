/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:00:23 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/05 19:02:34 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Ho perso");
// 	mlx_loop(mlx);
// }

// int	main(void)
// {
// 	t_data	solong;

// 	solong.mlx = mlx_init();
// 	solong.mlx_win = mlx_new_window(solong.mlx, 1920, 1080, "Ho perso");

// 	solong.img = mlx_new_image(solong.mlx, 1920, 1080);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	solong.addr = mlx_get_data_addr(solong.img, &solong.bits_per_pixel, &solong.line_length, &solong.endian);
// 	mlx_loop(solong.mlx);

// }

void	my_mlx_pixel_put(t_data *solong, int x, int y, int color)
{
	char	*dst;

	dst = solong->addr + (y * solong->line_length + x * (solong->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	solong;

	solong.mlx = mlx_init();
	solong.mlx_win = mlx_new_window(solong.mlx, 1920, 1080, "Hello world!");
	solong.img = mlx_new_image(solong.mlx, 1920, 1080);
	solong.addr = mlx_get_data_addr(solong.img, &solong.bits_per_pixel, &solong.line_length,
								&solong.endian);
	int i= -1;
	while(++i < 100)							
		my_mlx_pixel_put(&solong, i, i, 0x00FF0000);
	mlx_put_image_to_window(solong.mlx, solong.mlx_win, solong.img, 0, 0);
	mlx_loop(solong.mlx);
}


// int	close(int keycode, t_data *solong)
// {
// 	mlx_destroy_window(solong->mlx, solong->mlx_win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	solong;

// 	solong.mlx = mlx_init();
// 	solong.mlx_win = mlx_new_window(solong.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(solong.mlx_win, 2, 1L<<0, close, &solong);
// 	mlx_loop(solong.mlx);
// }