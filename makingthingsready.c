/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makingthingsready.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:02:07 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/12 20:08:18 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_checkarg(int argc)
{
	if (argc == 1)
	{
		printf("need a map");
		exit(2);
	}
	if (argc > 2)
	{
		printf("need only a valid map");
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
	printf("Error\nwrong extension");
	return (0);

}

void ft_beforestart(int argc, char **argv)
{
    ft_checkarg(argc);
    if(!ft_check_mapextension(argv[1]))
		exit(2);
	read map;
	ft_isagoodmap();

}