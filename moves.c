/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:52:30 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/29 18:31:14 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveup(t_game *newgame)
{
	if (newgame->map[newgame->player.pos.y - 1][newgame->player.pos.x] == 'C')
		newgame->collectible.nb -= 1;
	if (newgame->map[newgame->player.pos.y - 1][newgame->player.pos.x] == '1' ||
		newgame->map[newgame->player.pos.y - 1][newgame->player.pos.x] == 'E')
		;
	else
	{
		if (newgame->map[newgame->player.pos.y -1]
			[newgame->player.pos.x] == 'C')
			newgame->map[newgame->player.pos.y -1][newgame->player.pos.x] = '0';
		newgame->player.pos.y -= 1;
		newgame->nbmoves ++;
		ft_writemovenb(newgame);
	}
}

void	ft_moveleft(t_game *newgame)
{	
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x - 1] == 'C')
		newgame->collectible.nb -= 1;
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x - 1] == '1' ||
		newgame->map[newgame->player.pos.y][newgame->player.pos.x - 1] == 'E')
		;
	else
	{
		if (newgame->map[newgame->player.pos.y]
			[newgame->player.pos.x - 1] == 'C')
			newgame->map[newgame->player.pos.y][newgame->player.pos.x -1] = '0';
		newgame->player.pos.x -= 1;
		newgame->nbmoves ++;
		ft_writemovenb(newgame);
	}
}

void	ft_movedown(t_game *newgame)
{
	if (newgame->map[newgame->player.pos.y + 1][newgame->player.pos.x] == 'C')
		newgame->collectible.nb -= 1;
	if (newgame->map[newgame->player.pos.y + 1][newgame->player.pos.x] == '1' ||
		newgame->map[newgame->player.pos.y + 1][newgame->player.pos.x] == 'E')
		;
	else
	{
		if (newgame->map[newgame->player.pos.y + 1]
			[newgame->player.pos.x] == 'C')
			newgame->map[newgame->player.pos.y +1][newgame->player.pos.x] = '0';
		newgame->player.pos.y += 1;
		newgame->nbmoves ++;
		ft_writemovenb(newgame);
	}
}

void	ft_moveright(t_game *newgame)
{
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x + 1] == 'C')
		newgame->collectible.nb -= 1;
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x + 1] == '1' ||
		newgame->map[newgame->player.pos.y][newgame->player.pos.x + 1] == 'E')
		;
	else
	{
		if (newgame->map[newgame->player.pos.y]
			[newgame->player.pos.x + 1] == 'C')
			newgame->map[newgame->player.pos.y][newgame->player.pos.x +1] = '0';
		newgame->player.pos.x += 1;
		newgame->nbmoves ++;
		ft_writemovenb(newgame);
	}
}
