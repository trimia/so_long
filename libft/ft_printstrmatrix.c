/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:34:10 by mmariani          #+#    #+#             */
/*   Updated: 2022/12/14 20:28:39 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_countrow(char **matrix)
{
    int count;

    count = 0;
    while (matrix[count])
        count++;
    return (count);
}

void	ft_printstrmatrix(char **matrix)
{
	int	j;
	
	j = -1;
	while (++j != ft_countrow(matrix))
	{
		ft_putstr_fd(matrix[j], 1);
		write(1, "\n", 1);
	}
}
