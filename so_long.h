/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:31:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/14 20:27:05 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_data 
{
    void    *mlx;
    void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	char	**map;
	int		x;
	int		y;
	int		b;
	int		h;
	
}				t_game;


void	ft_beforestart(int argc, char **argv, t_game *newgame);
void	ft_checkarg(int argc);
int		ft_check_mapextension(char *file);
void	ft_readmap(t_game *newgame, char *file);
int		ft_countrow(char **matrix, int x);


void	ft_checkbs(char *map, int np, int nc, int ne);
void	ft_checkas(t_game *newgame);
void	ft_isagoodmap(char *map, t_game *newgame);
void	ft_anothebrickinthewall(t_game *newgame);
void	ft_rectanglecheck(t_game *newgame);




#endif