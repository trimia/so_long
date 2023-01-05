/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:04 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/06 00:06:50 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_game *newgame)
{
	if (key == 53)
		ft_close();
	else if (key == 15)
	{
		mlx_clear_window(newgame->mlx, newgame->window.reference);
		ft_setupthings(newgame);
		ft_readmap(newgame, newgame->str);
	}
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
