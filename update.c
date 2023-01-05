/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:48:15 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/05 23:51:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_updatecollectible(t_game *newgame, int *i, t_image *a)
{
		a->reference = newgame->collectible.img0.reference;
	if (*i >= FRAMES && *i < FRAMES * 2)
		a->reference = newgame->collectible.img1.reference;
	else if (*i >= FRAMES * 2 && *i < FRAMES * 3)
		a->reference = newgame->collectible.img2.reference;
	else if (*i >= FRAMES * 3 && *i < FRAMES * 5)
		a->reference = newgame->collectible.img3.reference;
	else if (*i >= FRAMES * 5 && *i < FRAMES * 7)
		a->reference = newgame->collectible.img4.reference;
	else if (*i >= FRAMES * 7 && *i < FRAMES * 9)
		a->reference = newgame->collectible.img5.reference;
	else if (*i >= FRAMES * 9 && *i < FRAMES * 11)
		a->reference = newgame->collectible.img6.reference;
	else if (*i >= FRAMES * 11 && *i < FRAMES * 13)
		a->reference = newgame->collectible.img7.reference;
	else if (*i >= FRAMES * 13 && *i < FRAMES * 15)
		a->reference = newgame->collectible.img8.reference;
	else if (*i >= FRAMES * 15 && *i < FRAMES * 17)
		a->reference = newgame->collectible.img9.reference;
	else if (*i >= FRAMES * 17)
	{
		a->reference = newgame->collectible.img10.reference;
		*i = 0;
	}
	*i += 1;
}

void	ft_updateplayer(t_game *newgame, int *i, t_image *a)
{
		a->reference = newgame->player.img0.reference;
	if (*i >= FRAMES && *i < FRAMES * 2)
		a->reference = newgame->player.img1.reference;
	else if (*i >= FRAMES * 2 && *i < FRAMES * 3)
		a->reference = newgame->player.img2.reference;
	else if (*i >= FRAMES * 3 && *i < FRAMES * 5)
		a->reference = newgame->player.img3.reference;
	else if (*i >= FRAMES * 5 && *i < FRAMES * 7)
		a->reference = newgame->player.img4.reference;
	else if (*i >= FRAMES * 7 && *i < FRAMES * 9)
		a->reference = newgame->player.img5.reference;
	else if (*i >= FRAMES * 9 && *i < FRAMES * 11)
		a->reference = newgame->player.img6.reference;
	else if (*i >= FRAMES * 17)
	{
		a->reference = newgame->player.img7.reference;
		*i = 0;
	}
	*i += 1;
}

void	ft_updateexit(t_game *newgame)
{
	if (newgame->collectible.nb > 0)
		newgame->exit.currentimg.reference = newgame->exit.img0.reference;
	else
		newgame->exit.currentimg.reference = newgame->exit.img1.reference;
}

void	ft_updatespikes(t_game *newgame, int *i, t_image *a)
{
		a->reference = newgame->floor.img1.reference;
	if (*i >= FRAMES && *i < FRAMES * 20)
	{
		a->reference = newgame->floor.img2.reference;
		newgame->floor.nb = 0;
	}
	else if (*i >= FRAMES * 20 && *i < FRAMES * 30)
	{
		newgame->floor.nb = 1;
		a->reference = newgame->floor.img3.reference;
	}
	else if (*i >= FRAMES * 30 && *i < FRAMES * 50)
	{
		a->reference = newgame->floor.img4.reference;
		*i = 0;
	}
	*i += 1;
}

int	ft_update(t_game *newgame)
{
	int	frame;

	frame = 0;
	ft_updatecollectible(newgame, &(newgame->collectible.framecount),
		&newgame->collectible.currentimg);
	ft_updateplayer(newgame, &(newgame->player.framecount),
		&newgame->player.currentimg);
	if (newgame->status == LOSE)
		ft_killelement(newgame, &newgame->player.framecount, &newgame->player);
	if (newgame->map[newgame->player.pos.y]
		[newgame->player.pos.x] == 'E' && newgame->collectible.nb == 0)
		newgame->status = WIN;
	if (newgame->map[newgame->player.pos.y][newgame->player.pos.x] == 'S'
		&& newgame->floor.nb == 1)
			newgame->status = LOSE;
	ft_updatespikes(newgame, &(newgame->floor.framecount),
		&newgame->floor.currentimg);
	ft_updateexit(newgame);
	ft_render(newgame);
	return (1);
}
