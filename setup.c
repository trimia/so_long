/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:36:54 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/29 17:39:20 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setupwindow(t_game *newgame, t_window *windows)
{
	windows->reference = mlx_new_window(newgame->mlx,
			windows->size.x, windows->size.y, windows->name);
	mlx_hook(windows->reference, 17, 0, ft_close, 0);
}

void	ft_setupthings(t_game *newgame)
{
	ft_findpos(newgame, 'E', &newgame->exit);
	newgame->nbmoves = 0;
	newgame->floor.nb = 0;
	newgame->status = 0;
	newgame->window.size.x = newgame->b * 32;
	newgame->window.size.y = newgame->h * 32;
}

void	ft_gameinitialize(t_game *newgame)
{
	newgame->mlx = mlx_init();
	ft_setupthings(newgame);
	ft_setupwindow(newgame, &newgame->window);
	ft_setupimage(newgame);
	mlx_loop_hook(newgame->mlx, ft_update, (void *)newgame);
	mlx_hook(newgame->window.reference, 2, 0, ft_input, (void *)newgame);
}

void	ft_youwin(t_game *newgame);
