/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:38:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/25 11:03:18 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_str;
	size_t	len_src;

	i = 0;
	len_str = ft_strlen(str);
	len_src = ft_strlen(src);
	j = len_str;
	if (len_str < size - 1 && size > 0)
	{
		while (src[i] && (len_str + i) < size - 1)
			str[j++] = src[i++];
		str[j] = '\0';
	}
	if (len_str >= size)
		len_str = size;
	return (len_str + len_src);
}
