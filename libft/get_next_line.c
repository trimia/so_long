/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:56:30 by mmariani          #+#    #+#             */
/*   Updated: 2022/11/16 19:27:51 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fdread(int fd, char *ret)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_newline(ret, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			if (ret)
				free(ret);
			return (NULL);
		}
		buffer[i] = '\0';
		ret = ft_gnlstrjoin(ret, buffer);
	}
	free(buffer);
	return (ret);
}

char	*ft_copy(char *ret)
{
	int		i;
	char	*temp;

	i = 0;
	if (!ret || !ret[i])
		return (NULL);
	while (ret[i] != '\n' && ret[i] != '\0')
		i++;
	if (ret[i] == '\0')
		temp = malloc(sizeof(char) * (i + 1));
	else
		temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = -1;
	while (ret[++i] && ret[i] != '\n')
		temp[i] = ret[i];
	if (ret[i] == '\n')
	{
		temp[i] = ret[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_trimstr(char *ret)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (ret[i] != '\n' && ret[i] != 0)
		i++;
	if (!ret[i])
	{
		free (ret);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_gnlstrlen(ret) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (ret[i])
		temp[j++] = ret[i++];
	temp[j] = '\0';
	free (ret);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*ret;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = fdread(fd, ret);
	if (!ret || *ret == '\0')
	{
		if (ret)
		{
			free (ret);
			ret = NULL;
		}
		return (NULL);
	}
	temp = ft_copy(ret);
	ret = ft_trimstr(ret);
	return (temp);
}
