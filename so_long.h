/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:31:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/12 20:02:22 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_data {
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


void	ft_beforestart(int argc, char **argv);
void	ft_checkarg(int argc);
int		ft_check_mapextension(char *file)
void	ft_readmap()
int		ft_countrow(char **matrix)


void	ft_isagoodmap();



#endif