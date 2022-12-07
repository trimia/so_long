/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteomariani <matteomariani@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:01:04 by mmariani          #+#    #+#             */
/*   Updated: 2022/11/18 15:56:48 by matteomaria      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*fdread(int fd, char *ret);
char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_trimstr(char *ret);
char	*ft_newline(char *str, int c);
int		ft_gnlcount(char *str);
int		ft_gnlstrlen(const char *str);
char	*ft_copy(char *ret);

#endif
