/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:03 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/29 17:32:49 by mmariani         ###   ########.fr       */
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

int	ft_close(void)
{
	exit(2);
}

void	ft_killelement(t_game *newgame, int *i, t_element *a)
{
	a->currentimg.reference = a->img9.reference;
	if (*i >= FRAMES && *i < FRAMES * 2)
		a->currentimg.reference = a->img10.reference;
	else if (*i >= FRAMES * 2 && *i < FRAMES * 3)
		a->currentimg.reference = a->img11.reference;
	else if (*i >= FRAMES * 3 && *i < FRAMES * 5)
		a->currentimg.reference = newgame->floor.img4.reference;
}

void	ft_writemovenb(t_game *newgame)
{
	ft_putstr_fd("moves nb ", 1);
	ft_putnbr_fd(newgame->nbmoves, 1);
	ft_putchar_fd('\n', 1);
}
