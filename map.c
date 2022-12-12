/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:33 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/12 20:08:17 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_readmap(t_game *newgame, char *file)
{
    int     fd;
    char    *line;
    char    *map;

    
    map = ft_calloc(1, 1);
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        map = ft_gnlstrjoin(map, line);
        line = get_next_line(fd);
    }
    close(fd);
    newgame->map = ft_split(map,'\n');
    newgame->b = ft_strlen(newgame->map[0]);
    newgame->h = ft_countrow(newgame->map);
    free(map);

}

void	ft_isagoodmap(char *map, t_game *newgame)
{
    int np;
    int i;

    np = 0;
    i = 0;
    while (map[i])
    {
        if(map[i] == "P")
            np += 1;
        if(map[i] == "0" || map[i] == "1" || map[i] == "C" || map[i] == "E" || map[i] == "P" || (map[i] == '\n' && i != newgame->b))
            i++;
        else 
            exit(2);
    }
    -at least 1 p 1 c 1 e
    -map sorrounded by the w_stopval
    -rectangular map
}
