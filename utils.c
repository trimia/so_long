/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:03 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/23 19:40:41 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_singlecountrow(char **matrix, int x)
{
	int	count;

	count = 0;
	while (matrix[x][count])
		count++;
	return (count);
}

int	ft_countrow(char **matrix)
{
	int	count;

	count = 0;
	while (matrix[count])
		count++;
	return (count);
}

int	ft_close()
{
	exit(2);
}

void	ft_readwin(t_game *newgame, char *file)
{
	int		fd;
	char	*line;
	char	*map;

	map = ft_calloc(1, 1);
	fd = open(file, O_RDONLY);
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
	free(map);

}