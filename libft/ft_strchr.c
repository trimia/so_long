/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:09:38 by mmariani          #+#    #+#             */
/*   Updated: 2022/01/20 11:41:58 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	s--;
	while (*(++s))
		if (*s == (char)c)
			return ((char *)s);
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}
