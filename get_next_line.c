/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:55 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/24 14:11:58 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	int			i;

	i = 0;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (i >= 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		line = ft_strjoin(0, buff);
	}
}
