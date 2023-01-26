/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrmatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:43:11 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/26 17:20:25 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrmatrix(char **matrix, int size)
{
	int	i;

	i = -1;
	while (++i < size + 1)
		free(matrix[i]);
	free(matrix);
}
