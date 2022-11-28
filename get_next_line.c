/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:55 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/28 11:56:43 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_holder(char *holder);
static char	*check_newline(char *s, char *holder);

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*all;
	char		*stretch;
	int			i;

	i = 1;
	all = NULL;
	stretch = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!stretch || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (i > 0)
	{
		if (holder && check_holder(holder) == 0)
		{
			i = read(fd, stretch, BUFFER_SIZE);
			all = ft_strjoin(holder, stretch);
			free(holder);
		}
		else if (check_holder(holder) > 0)
			all = ft_strdup(holder);
		else
			all = ft_strjoin(all, stretch);
		return (check_newline(all, holder));
	}
}

static int	check_holder(char *holder)
{
	int	i;

	i = 0;
	while (holder[i])
	{
		if (holder[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*check_newline(char *s, char *holder)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		line = ft_substr(s, 0, i);
		if (holder)
			free(holder);
		holder = ft_substr(s, i + 1, (ft_strlen(s) - i));
	}
	else
		line = ft_strdup(s);
	return (line);
}
