/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/22 19:40:06 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_drawmap(t_game *newgame,char type, int b, int h)
{
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->floor.img0.reference, b * 32, h * 32);
	if (type == '1')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->wall.img0.reference, b * 32, h * 32);
	else if (type == 'E')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->exit.currentimg.reference, b * 32, h * 32);
	else if (type == 'C')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->collectible.currentimg.reference, b * 32, h * 32);
	else if (type == 'P')
	{
		newgame->player.coor.x = b;
		newgame->player.coor.y = h;
		// printf("\nx draw %d\n",newgame->player.coor.x);
		// printf("\ny draw %d\n",newgame->player.coor.y);
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference, newgame->player.currentimg.reference, b * 32, h * 32);
	}
		
}

void	ft_render (t_game newgame)
{
	int b;
	int h;

	b = -1;
	h = -1;
	// mlx_clear_window(newgame.mlx, newgame.window.reference);
	while (++b < newgame.h)
	{

		h = -1;
		while (++h < newgame.b)
			ft_drawmap(&newgame,newgame.map[b][h],h,b);
		// printf("\n b %d newgame.b %d\n",b,newgame.b);
	}
	// printf("\nhofiniton");
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