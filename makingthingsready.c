/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makingthingsready.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:02:07 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/30 19:56:27 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkarg(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\nneed a map", 1);
		exit(2);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error\nneed only a valid map", 1);
		exit(2);
	}
}

int	ft_check_mapextension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[--i] == 'r')
		if (file[--i] == 'e')
			if (file[--i] == 'b')
				if (file[--i] == '.')
					return (1);
	ft_putstr_fd("Error\nwrong extension", 1);
	return (0);
}

void	ft_beforestart(int argc, char **argv, t_game *newgame)
{
	ft_checkarg(argc);
	if (!ft_check_mapextension(argv[1]))
		exit(2);
	newgame->window.name = ft_strdup(argv[1]);
	ft_readmap(newgame, argv[1]);
	newgame->str = ft_strdup(argv[1]);
}

void	ft_findpos(t_game *newgame, char type, t_element *element)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < newgame->h)
	{
		x = -1;
		while (++x < newgame->b)
		{
			if (newgame->map[y][x] == type)
			{
				element->pos.x = x;
				element->pos.y = y;
			}
		}
	}
}

void	ft_readmap(t_game *newgame, char *file)
{
	int		fd;
	char	*line;
	char	*map;

	map = ft_calloc(1, 1);
	fd = open(file, O_RDONLY);
	ft_checkfd(newgame, fd);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_gnlstrjoin(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	newgame->map = ft_split(map, '\n');
	newgame->b = (int)ft_strlen(newgame->map[0]);
	newgame->h = ft_countrow(newgame->map);
	ft_findpos(newgame, 'P', &newgame->player);
	newgame->collectible.nb = ft_checkbs(map, 0, 0, 0);
	ft_checkas(newgame);
	ft_anothebrickinthewall(newgame);
	free(map);
}
