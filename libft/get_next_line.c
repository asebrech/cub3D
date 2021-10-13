/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:48:24 by asebrech          #+#    #+#             */
/*   Updated: 2021/10/13 10:21:48 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isend(char *s, char c)
{
	int			i;

	i = 0;
	if (s[i])
	{
		while (s[i] && (s[i] != c))
			i++;
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

ssize_t	ft_save_gest(char **save, ssize_t ret, char *buf, int fd)
{
	if (save[fd] != NULL)
	{
		ft_strlcpy(buf, save[fd], ft_strlen(save[fd]) + 1);
		free(save[fd]);
		save[fd] = NULL;
	}
	else
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
	}
	return (ret);
}

int	ft_find_join(char *buf, char **line, char **save, int fd)
{
	int		index;
	char	*b_nl;
	char	*tmp;

	index = ft_isend(buf, '\n');
	if (index != -1)
	{
		b_nl = ft_substr(buf, 0, index);
		tmp = *line;
		*line = ft_strjoin(tmp, b_nl);
		free(tmp);
		free(b_nl);
		if ((buf + index + 1) != NULL)
			save[fd] = ft_strdup(buf + index + 1);
		return (1);
	}
	else
	{	
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*save[255];

	if (fd < 0 || fd > 255 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = ft_save_gest(save, ret, buf, fd);
		if (ret < 0)
			return (-1);
		if (!*line)
			*line = ft_calloc(1, sizeof(char));
		if (ft_find_join(buf, &*line, save, fd) == 1)
			return (1);
	}
	return (0);
}
