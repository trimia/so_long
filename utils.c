/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:03 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/16 12:28:28 by mmariani         ###   ########.fr       */
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