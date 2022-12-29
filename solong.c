/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:18:19 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/29 17:30:20 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	newgame;

	ft_beforestart(argc, argv, &newgame);
	ft_gameinitialize(&newgame);
	// ft_printstrmatrix(newgame.map);
	mlx_loop(newgame.mlx);
}
