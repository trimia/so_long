/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/29 18:26:37 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_game *newgame)
{
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x] == 'S'
		&& newgame->floor.nb == 1)
			newgame->status = -1;
	else if (key == 53)
		ft_close();
	else if (key == 15)
	{
		newgame->nbmoves = 0;
		newgame->status = 0;
		ft_readmap(newgame, newgame->str);
	}
	else if (newgame->map[newgame->player.pos.y - 1]
		[newgame->player.pos.x] == 'E' && newgame->collectible.nb == 0)
		newgame->status = 1;
	else if (key == 13 || key == 126 && newgame->status == GODOT)
		ft_moveup(newgame);
	else if (key == 0 || key == 123 && newgame->status == GODOT)
		ft_moveleft(newgame);
	else if (key == 1 || key == 125 && newgame->status == GODOT)
		ft_movedown(newgame);
	else if (key == 2 || key == 124 && newgame->status == GODOT)
		ft_moveright(newgame);
	return (0);
}
