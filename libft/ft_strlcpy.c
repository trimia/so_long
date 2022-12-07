/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:38:01 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/01 10:51:53 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *str, const char *src, size_t size)
{
	size_t	i;

	i = ft_strlen(src);
	if (size != 0)
	{
		while (*src && --size)
			*str++ = *src++;
		*(str) = '\0';
	}
	return (i);
}
