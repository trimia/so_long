/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:36:54 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/22 19:02:44 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	ft_setupwindow(t_game *newgame)
{
	newgame->window.size.x = newgame->b * 32;
	newgame->window.size.y = newgame->h * 32;
	newgame->window.reference = mlx_new_window(newgame->mlx, newgame->window.size.x, newgame->window.size.y, newgame->window.name);
	mlx_hook(newgame->window.reference,17,0,ft_close,0);
}

void	ft_gameinitialize(t_game *newgame)
{
	newgame->mlx = mlx_init();
	ft_setupwindow(newgame);
	ft_setupimage(newgame);
	mlx_loop_hook(newgame->mlx, ft_update, (void *)newgame);
	mlx_hook(newgame->window.reference, 2, 0, ft_input, (void *)newgame);

}
