/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:55 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/12/02 13:09:22 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store_read(char *holder)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (holder[i] != '\n')
		i++;
	i++;
	temp = (char *)malloc(sizeof(char) * ((int)ft_strlen(holder) - i));
	while (j < ((int)ft_strlen(holder) - i))
		temp[j++] = holder[++i];
	free(holder);
	holder = ft_strjoin(0, temp);
	return (holder);
}

static char	*check_line(char *holder)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (holder[i] != '\n' || holder [i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j < i + 2)
	{
		if (holder[j] == '\0')
			line[j] = '\n';
		line[j] = holder[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		stretch[BUFFER_SIZE + 1];
	static char	*holder;

	i = 1;
	holder = ft_strjoin(0, stretch);
	if (!holder || fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, stretch, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		stretch[i] = '\0';
		holder = ft_strjoin(holder, stretch);
		if (ft_strchr(stretch, '\n'))
			break ;
	}
	line = check_line(holder);
	holder = store_read(holder);
	return (line);
}
