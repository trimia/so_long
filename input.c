/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/30 19:56:06 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_game *newgame)
{
	// if (newgame->map[newgame->player.pos.y][newgame->player.pos.x] == 'S'
	// 	&& newgame->floor.nb == 1)
	// 		newgame->status = LOSE;
	if (key == 53)
		ft_close();
	else if (key == 15)
	{
		// mlx_destroy_image(newgame->mlx,newgame->win.background.reference);
		mlx_clear_window(newgame->mlx,newgame->window.reference);
		ft_setupthings(newgame);
		ft_readmap(newgame, newgame->str);
	}
	// if (newgame->map[newgame->player.pos.y]
	// 	[newgame->player.pos.x] == 'E' && newgame->collectible.nb == 0)
	// 	newgame->status = WIN;
	else if ((key == 13 || key == 126) && newgame->status == GODOT)
		ft_moveup(newgame);
	else if ((key == 0 || key == 123) && newgame->status == GODOT)
		ft_moveleft(newgame);
	else if ((key == 1 || key == 125) && newgame->status == GODOT)
		ft_movedown(newgame);
	else if ((key == 2 || key == 124) && newgame->status == GODOT)
		ft_moveright(newgame);
	return (0);
}

void	ft_checkfd(t_game *newgame, int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error\nimpossible read map", 1);
		exit(2);
	}
}