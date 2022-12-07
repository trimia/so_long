/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:45:18 by mmariani          #+#    #+#             */
/*   Updated: 2022/02/16 13:24:35 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	s += ft_strlen(s);
	if (c == 0)
		return ((char *)s);
	while (--s >= str)
		if (*s == (char)c)
			return ((char *)s);
	return (NULL);
}
