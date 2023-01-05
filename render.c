/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/06 00:18:17 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawmap(t_game *newgame, char type, int b, int h)
{
	int	x;
	int	y;

	x = newgame->window.scale.x;
	y = newgame->window.scale.y;
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
		newgame->floor.img0.reference, b * 32 + x, (h * 32) + y);
	if (type == '1')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->wall.img0.reference, b * 32 + x, (h * 32) + y);
	else if (type == 'E')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->exit.currentimg.reference, b * 32 + x, (h * 32) + y);
	else if (type == 'C')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->collectible.currentimg.reference, b * 32 + x, h * 32 + y);
	else if (type == 'S')
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->floor.currentimg.reference, b * 32 + x, (h * 32) + y);
}

void	ft_drawplayer(t_game *newgame)
{
	int	x;
	int	y;

	x = newgame->window.scale.x;
	y = newgame->window.scale.y;
	mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
		newgame->player.currentimg.reference,
		newgame->player.pos.x * 32 + x, newgame->player.pos.y * 32 + y);
}

void	ft_drawtext(t_game *newgame)
{
	char	*str;
	int		x;
	int		y;

	x = newgame->window.scale.x;
	y = newgame->window.scale.y;
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
	mlx_clear_window(newgame->mlx, newgame->window.reference);
	while (++b < newgame->h)
	{
		h = -1;
		while (++h < newgame->b)
			ft_drawmap(newgame, newgame->map[b][h], h, (b));
		ft_drawtext(newgame);
		ft_drawplayer(newgame);
	}
	if (newgame->status == WIN)
		mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
			newgame->win.background.reference, (newgame->window.size.x - 540)
			/ 2, (newgame->window.size.y - 360) / 2);
	else if (newgame->status == LOSE)
		if (newgame->player.nb >= 10)
			mlx_put_image_to_window(newgame->mlx, newgame->window.reference,
				newgame->lose.background.reference,
				(newgame->window.size.x - 500)
				/ 2, (newgame->window.size.y - 300) / 2);
}
