/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:18:19 by matteomaria       #+#    #+#             */
/*   Updated: 2023/01/06 00:24:14 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	newgame;

	ft_beforestart(argc, argv, &newgame);
	ft_gameinitialize(&newgame);
	mlx_loop(newgame.mlx);
}
