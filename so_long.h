/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:31:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/06 00:23:58 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

# ifndef FRAMES
#  define FRAMES 5
# endif

# define WIN 1
# define LOSE -1
# define GODOT 0

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef enum e_kind
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
}			t_kind;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	t_vector	pos;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

/* A pointer to the window and its size */
typedef struct s_window
{
	void		*reference;
	char		*name;
	t_image		background;
	t_vector	size;
	t_vector	scale;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}				t_color;

typedef struct s_element
{
	int			framecount;
	int			nb;
	void		*reference;
	t_vector	pos;
	t_image		currentimg;
	t_image		img0;
	t_image		img1;
	t_image		img2;
	t_image		img3;
	t_image		img4;
	t_image		img5;
	t_image		img6;
	t_image		img7;
	t_image		img8;
	t_image		img9;
	t_image		img10;
	t_image		img11;

}				t_element;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	t_window	window;
	t_window	win;
	t_window	lose;
	t_element	player;
	t_element	collectible;
	t_element	exit;
	t_element	floor;
	t_element	wall;
	int			nbmoves;
	char		*str;
	int			status;
	int			b;
	int			h;
}				t_game;

void	ft_beforestart(int argc, char **argv, t_game *newgame);
void	ft_checkarg(int argc);
int		ft_check_mapextension(char *file);
void	ft_readmap(t_game *newgame, char *file);
int		ft_countrow(char **matrix);
int		ft_singlecountrow(char **matrix, int x);
int		ft_checkbs(char *map, int np, int nc, int ne);
void	ft_checkas(t_game *newgame);
void	ft_isagoodmap(char *map, t_game *newgame);
void	ft_anothebrickinthewall(t_game *newgame);
void	ft_rectanglecheck(t_game *newgame);
void	ft_setupthings(t_game *newgame);
void	ft_gameinitialize(t_game *newgame);
void	ft_setupwindow(t_game *newgame, t_window *windows);
void	ft_render(t_game *newgame);
void	ft_setupimage(t_game *newgame);
int		ft_close(void);
void	ft_drawmap(t_game *newgame, char type, int b, int h);
void	ft_assignimage(t_game *newgame, t_image *image, char *str);
void	ft_updatecollectible(t_game *newgame, int *i, t_image *a);
void	ft_updateplayer(t_game *newgame, int *i, t_image *a);
void	ft_updateexit(t_game *newgame);
void	ft_updatespikes(t_game *newgame, int *i, t_image *a);
int		ft_update(t_game *newgame);
int		ft_input(int key, t_game *newgame);
void	ft_findpos(t_game *newgame, char type, t_element *element);
void	ft_moveup(t_game *newgame);
void	ft_moveleft(t_game *newgame);
void	ft_movedown(t_game *newgame);
void	ft_moveright(t_game *newgame);
void	ft_youwin(t_game *newgame);
void	ft_readwin(t_game *newgame, char *file);
void	ft_drawtext(t_game *newgame);
void	ft_killelement(t_game *newgame, int *i, t_element *a);
void	ft_writemovenb(t_game *newgame);
void	ft_setupplayerimg(t_game *newgame);
void	ft_setupspikesimg(t_game *newgame);
void	ft_checkfd(t_game *newgame, int fd);

#endif