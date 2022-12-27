/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/26 10:37:03 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_input(int key, t_game *newgame)
{
	int i;

	i = 0;
	// mlx_hook(newgame->window.reference,53,0,ft_close,0);

	if (key == 13 || key == 126) //up
		ft_moveup(newgame);
	else if (key == 0 || key == 123) //left
		ft_moveleft(newgame);
	else if (key == 1 || key == 125) //down
		ft_movedown(newgame);	
	else if (key == 2 || key == 124) //right
		ft_moveright(newgame);
	else if (key == 53)
		ft_close();
	else if (key == 15)
	{
		newgame->nbmoves = 0;
		newgame->status = 0;
		ft_readmap(newgame, newgame->str);
	}
	return (i); 
}