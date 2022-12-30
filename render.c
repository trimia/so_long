/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/30 18:25:16 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawmap(t_game *newgame, char type, int b, int h)
{
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
		newgame->floor.img0.reference, b * 32, h * 32);
	if (type == '1')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->wall.img0.reference, b * 32, h * 32);
	else if (type == 'E')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->exit.currentimg.reference, b * 32, h * 32);
	else if (type == 'C')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->collectible.currentimg.reference, b * 32, h * 32);
	else if (type == 'S')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->floor.currentimg.reference, b * 32, h * 32);
}

void	ft_drawplayer(t_game *newgame)
{
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
		newgame->player.currentimg.reference,
		newgame->player.pos.x * 32, newgame->player.pos.y * 32);
}

void	ft_drawtext(t_game *newgame)
{
	char	*str;

	str = ft_itoa(newgame->nbmoves);
	mlx_string_put(newgame->mlx, newgame->window.reference,
		newgame->window.size.x -100, 0, -1, str);
	free(str);
}

void	ft_render(t_game *newgame)
{
	int	b;
	int	h;

	b = -1;
	h = -1;
	// if (newgame->status == WIN)
	// {
	// 	mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
	// 		newgame->win.background.reference,
	// 		(newgame->b / 2), (newgame->h / 2) * 16);
	// }
	while (++b < newgame->h)
	{
		h = -1;
		while (++h < newgame->b)
			ft_drawmap(newgame, newgame->map[b][h], h, b);
		ft_drawtext(newgame);
		ft_drawplayer(newgame);
	}
	if (newgame->status == GODOT)
		;
	else if (newgame->status == WIN)
	{
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->win.background.reference,
			(newgame->b / 2), (newgame->h / 2) * 16);
	}
	else if (newgame->status == LOSE && newgame->player.nb == 1)
	{
		// ft_killelement(newgame, &newgame->player.framecount, &newgame->player);
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->lose.background.reference,
			(newgame->b / 2), (newgame->h / 2) * 16);
	}
}
