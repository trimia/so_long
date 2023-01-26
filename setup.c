/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:36:54 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/26 16:13:46 by mmariani         ###   ########.fr       */
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
	newgame->player.nb = 0;
	newgame->status = GODOT;
	newgame->window.scale.x = 0;
	newgame->window.scale.y = 0;
	newgame->window.size.x = newgame->b * 32;
	newgame->window.size.y = newgame->h * 32;
	if (newgame->b * 32 < 540)
		newgame->window.size.x = 540;
	if (newgame->h * 32 < 360)
		newgame->window.size.y = 360;
	newgame->window.scale.x = (newgame->window.size.x - newgame->b * 32) / 2;
	newgame->window.scale.y = (newgame->window.size.y - newgame->h * 32) / 2;
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

int	ft_check_newline(char *line)
{
	int	i;

	i = 1;
	if (line[0] == '\n')
	{
		ft_putstr_fd("Error\nwrong map",1);
		exit(2);
	}
	while (line[i])
	{
		if (line[i] == '\n' && line[i - 1] == '\n')
		{
			ft_putstr_fd("Error\nwrong map",1);
			exit(2);
		}
		i++;
	}
	if (line[i - 1] == '\n')
	{
		ft_putstr_fd("Error\nwrong map",1);
		exit(2);
	}
	return (1);
}