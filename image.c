/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/29 18:45:44 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assignimage(t_game *newgame, t_image *image, char *str)
{
	image->reference = mlx_xpm_file_to_image(newgame->mlx, str,
			&image->size.x, &image->size.y);
}

void	ft_setupimage(t_game *newgame)
{
	ft_setupplayerimg(newgame);
	ft_setupspikesimg(newgame);
	ft_assignimage(newgame, &newgame->collectible.img0, "coin/coin00.xpm");
	ft_assignimage(newgame, &newgame->collectible.img1, "coin/coin01.xpm");
	ft_assignimage(newgame, &newgame->collectible.img2, "coin/coin02.xpm");
	ft_assignimage(newgame, &newgame->collectible.img3, "coin/coin03.xpm");
	ft_assignimage(newgame, &newgame->collectible.img4, "coin/coin04.xpm");
	ft_assignimage(newgame, &newgame->collectible.img5, "coin/coin05.xpm");
	ft_assignimage(newgame, &newgame->collectible.img6, "coin/coin06.xpm");
	ft_assignimage(newgame, &newgame->collectible.img7, "coin/coin07.xpm");
	ft_assignimage(newgame, &newgame->collectible.img8, "coin/coin08.xpm");
	ft_assignimage(newgame, &newgame->collectible.img9, "coin/coin09.xpm");
	ft_assignimage(newgame, &newgame->collectible.img10, "coin/coin10.xpm");
	ft_assignimage(newgame, &newgame->wall.img0, "XPM/wall00.xpm");
	ft_assignimage(newgame, &newgame->exit.img0, "XPM/doors_leaf_closed.xpm");
	ft_assignimage(newgame, &newgame->exit.img1, "XPM/doors_leaf_open.xpm");
	ft_assignimage(newgame, &newgame->floor.img0, "XPM/floor.xpm");
	ft_assignimage(newgame, &newgame->lose.background, "XPM/gameover.xpm");
	ft_assignimage(newgame, &newgame->win.background, "youwin.xpm");
	ft_assignimage(newgame, &newgame->lose.background, "gameover.xpm");
}

void	ft_setupplayerimg(t_game *newgame)
{
	ft_assignimage(newgame, &newgame->player.img0, "xpmplayer/player00.xpm");
	ft_assignimage(newgame, &newgame->player.img1, "xpmplayer/player01.xpm");
	ft_assignimage(newgame, &newgame->player.img2, "xpmplayer/player02.xpm");
	ft_assignimage(newgame, &newgame->player.img3, "xpmplayer/player03.xpm");
	ft_assignimage(newgame, &newgame->player.img4, "xpmplayer/player04.xpm");
	ft_assignimage(newgame, &newgame->player.img5, "xpmplayer/player05.xpm");
	ft_assignimage(newgame, &newgame->player.img6, "xpmplayer/player06.xpm");
	ft_assignimage(newgame, &newgame->player.img7, "xpmplayer/player07.xpm");
	ft_assignimage(newgame, &newgame->player.img8, "xpmplayer/player08.xpm");
	ft_assignimage(newgame, &newgame->player.img9,
		"xpmplayer/playerdisappear00.xpm");
	ft_assignimage(newgame, &newgame->player.img10,
		"xpmplayer/playerdisappear01.xpm");
	ft_assignimage(newgame, &newgame->player.img11,
		"xpmplayer/playerdisappear02.xpm");
}

void	ft_setupspikesimg(t_game *newgame)
{
	ft_assignimage(newgame, &newgame->floor.img1,
		"floor_spikes/floor_spikes_anim_f0.xpm");
	ft_assignimage(newgame, &newgame->floor.img2,
		"floor_spikes/floor_spikes_anim_f1.xpm");
	ft_assignimage(newgame, &newgame->floor.img3,
		"floor_spikes/floor_spikes_anim_f2.xpm");
	ft_assignimage(newgame, &newgame->floor.img4,
		"floor_spikes/floor_spikes_anim_f3.xpm");
}
