/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/27 11:55:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_drawmap(t_game *newgame,char type, int b, int h)
{
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->floor.img0.reference, b * 32, h * 32);
	if (type == 'S')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->floor.currentimg.reference, b * 32, h * 32);
	if (type == '1')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->wall.img0.reference, b * 32, h * 32);
	else if (type == 'E')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->exit.currentimg.reference, b * 32, h * 32);
	else if (type == 'C')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->collectible.currentimg.reference, b * 32, h * 32);
	else if (type == 'P')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->player.currentimg.reference, b * 32, h * 32);
	else if (type == 'S')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->floor.currentimg.reference, b * 32, h * 32);
}

void	ft_drawtext(t_game *newgame)
{
	char	*str;

	str = ft_itoa(newgame->nbmoves);
	mlx_string_put(newgame->mlx, newgame->window.reference,
		newgame->window.size.x -25, 25, -1, str);
	free(str);
}

void	ft_render (t_game *newgame)
{
	int b;
	int h;

	b = -1;
	h = -1;
	// mlx_clear_window(newgame.mlx, newgame.window.reference);
	while (++b < newgame->h)
	{

		h = -1;
		while (++h < newgame->b)
			ft_drawmap(newgame,newgame->map[b][h],h,b);
		ft_drawtext(newgame);
	}
	if (newgame->status == 0)
		;
	else if (newgame->status == 1)
	{
		// mlx_clear_window(newgame->mlx, newgame->window.reference);
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->win.background.reference, newgame->b/2,newgame->h/2);
	}
	else if (newgame->status == -1)
		;
	// ++b;
	// ++h;
	// if(b != newgame.b && h > newgame.h)
	// {
	// 	h=-1;
	// 	printf("\n b %d newgame.b %d\n",b,newgame.b);
	// 	printf("\n h %d newgame.h %d\n",h,newgame.h);


	// }
	// ft_drawmap(&newgame,newgame.map[b][h],h,b);

	// printf("\n b %d newgame.b %d\n",b,newgame.b);
	// 	printf("\n h %d newgame.h %d\n",h,newgame.h);
	// mlx_put_image_to_window(newgame.mlx, newgame.window.reference, newgame.floor.img0.reference, b * 32, h * 32);

	// ft_drawmap(newgame,newgame.map[b][h],h,b);
}
