/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeintmatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:43:11 by mmariani          #+#    #+#             */
/*   Updated: 2023/01/26 16:45:00 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_intmatrix(int **matrix, int size)

{
	int	i;

	i = -1;
	while (++i < size)
		free(matrix[i]);
	free(matrix);
}
