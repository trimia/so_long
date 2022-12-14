/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:33 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/14 20:45:55 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	ft_checkbs(char *map, int np, int nc, int ne)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
			np += 1;
		if (map[i] == 'C')
			nc += 1;
		if (map[i] == 'E')
			ne += 1;
	}
	if (np > 1)
	{
		ft_putstr_fd("Error\nonly one Player", 1);
		exit(2);
	}
	if (!(nc >= 1 && np == 1 && ne >= 1))
	{
		ft_putstr_fd("Error\nat least one Player one Collectible one Exit", 1);
		exit(2);
	}
	// before split:
	// 	-only one carachter
	// 	-at least 1 p 1 c 1 e
}

void	ft_checkas(t_game *newgame)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (newgame->map[y])
	{
		// printf("ywhile");
		while (newgame->map[y][x])
		{
			// printf("xwhile");

			if (newgame->map[y][x] == '0'|| newgame->map[y][x] == '1'|| newgame->map[y][x] == 'C'|| newgame->map[y][x] == 'E'|| newgame->map[y][x] == 'P')
				{x++;
				printf(" %c ",newgame->map[x][y]);
				
				}

			else
			{
				ft_putstr_fd("Error\nwrong syntax in the map", 1);
				exit(2);
			}
		}
		x = 0;
		y++;
	}
	
	// after split:
	// 	-valid map only 0,1,C,E,P
	// 	-map sorrounded by the wall
	// 	-rectangular map
}


void	ft_anothebrickinthewall(t_game *newgame)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x != newgame->b)
	{
		if (newgame->map[0][x] == '1' && newgame->map[newgame->h-1][x] == '1')
			x++;
		else
		{
			ft_putstr_fd("Error\nneed another brick in the wall (x)", 1);
			exit(2);
		}
	}
	while (y != newgame->h)
	{
		if (newgame->map[y][0] == '1' && newgame->map[y][newgame->b -1] == '1')
			y++;
		else
		{
			ft_putstr_fd("Error\nneed another brick in the wall (y)", 1);
			exit(2);
		}
	}
}

void ft_rectanglecheck(t_game *newgame)
{
	int	i;

	i = -1;
	while (++i != newgame->h)
	{
		if(!((int)ft_strlen(newgame->map[i]) == newgame->b))
		{
			ft_putstr_fd("Error\nnot a rectangle (x)",1);
			exit(2);
		}
	}
	i = -1;
	while (++i != newgame->b)
	{
		if(!((int)ft_countrow(newgame->map, i) == newgame->h))
		{
			ft_putstr_fd("Error\nnot a rectangle (y)",1);
			exit(2);
		}
	}
}