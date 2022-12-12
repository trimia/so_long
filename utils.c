/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:03 by matteomaria       #+#    #+#             */
/*   Updated: 2022/12/12 20:02:27 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_countrow(char **matrix)
{
    int count;

    count = 0;
    while (matrix[count])
        count++;
    return (count);
}