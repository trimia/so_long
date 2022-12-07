/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:58:57 by trimia            #+#    #+#             */
/*   Updated: 2022/03/08 18:34:27 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_power(int nb, int power)
{
	int	x;

	x = nb;
	if (power == 0)
		return (1);
	while (--power)
		nb *= x;
	return (nb);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_litoa(int n, char *str)
{
	int		j;
	int		i;
	int		k;

	i = ft_count(n);
	k = ft_count(n) - 1;
	if (n < 0)
	{
		n = n * -1;
		*str = 45;
	}
	else
		str--;
	while (i-- > 1 && n > 9)
	{	
		j = (n / ft_power(10, i));
		*(++str) = j + '0';
		n = n - j * ft_power(10, i);
		while (--k > 0 && n < 10)
			*(++str) = '0';
	}
	if (n < 10)
		*(++str) = n + '0';
	*(++str) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*temp;
	int		i;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (!str)
			return (NULL);
		return (str);
	}
	i = ft_count(n);
	if (n < 0)
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_litoa(n, str);
	temp = str;
	return (temp);
}
