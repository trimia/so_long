/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:04:51 by mmariani          #+#    #+#             */
/*   Updated: 2022/11/18 15:56:45 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnlstrlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	toomanylines(char *s1, char *s2)
{
	if (!s2)
	{
		free (s1);
		return (0);
	}
	return (1);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*temp;
	int		j;
	int		i;
	int		size;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	size = ft_gnlstrlen(s1) + ft_gnlstrlen(s2);
	if (!toomanylines(s1, s2))
		return (NULL);
	temp = malloc(sizeof(char) * (size + 1));
	if (temp == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		temp[j] = s1[j];
	i = 0;
	while (s2[i])
		temp[j++] = s2[i++];
	temp[size] = '\0';
	free (s1);
	return (temp);
}

char	*ft_newline(char *str, int c)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *) &str[ft_gnlstrlen(str)]);
	while (str[++i] != '\0')
		if (str[i] == (char) c)
			return ((char *)&str[i]);
	return (0);
}

int	ft_gnlcount(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str)
	{
		while (str[i] != '\n')
			i++;
		return (i);
	}
	return (0);
}
