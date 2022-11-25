/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:55 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/25 15:00:13 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*stretch;
	int			i;
	int			len_b;

	i = 1;
	len_b = 0;
	buffer = NULL;
	stretch = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stretch || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, stretch, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, stretch);
		buffer[i] = '\0';
	}
}
