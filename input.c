/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/22 19:55:36 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_input(int key, t_game *newgame)
{
	int i;

	i = 0;
	// mlx_hook(newgame->window.reference,53,0,ft_close,0);

	if (key == 13)
	{
		printf("\npria %c\n",newgame->map[newgame->player.coor.y][newgame->player.coor.x]);
		newgame->map[newgame->player.coor.y][newgame->player.coor.x] = '0'; 
		newgame->map[newgame->player.coor.y + 1][newgame->player.coor.x] = 'P'; 
		// newgame->map[newgame->player.coor.y + 1][newgame->player.coor.x + 1] = 'P';
		printf("\npost %c\n",newgame->map[newgame->player.coor.y][newgame->player.coor.x]);
		
		printf("\nx %d\n",newgame->player.coor.x);
		printf("\ny %d\n",newgame->player.coor.y);
	}
	if (key == 53)
		ft_close();
	return (i); 
}