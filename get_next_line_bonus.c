/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlayine <zlayine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:48:31 by zlayine           #+#    #+#             */
/*   Updated: 2019/12/10 15:03:07 by zlayine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_newln_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i] == '\n')
			break ;
		else
			i++;
	return (i);
}

char	*new_str(char *str, char *data)
{
	if (str)
		free(str);
	str = data;
	return (str);
}

int		free_bufs(char *b1, char *b2, int ret)
{
	if (ret == -1)
	{
		new_str(b1, NULL);
		new_str(b2, NULL);
	}
	return (ret);
}

int		make_next_line(char **s, char **line, int fd)
{
	int		i;
	char	*tmp;

	if (s[fd])
	{
		if (ft_strchr(s[fd], '\n'))
		{
			i = get_newln_len(s[fd]);
			*line = new_str(*line, ft_substr(s[fd], 0, i));
			s[fd] = new_str(s[fd], ft_strdup(s[fd] + i + 1));
			if (!*line || !s[fd])
				return (-1);
			return (1);
		}
		else if (ft_strlen(s[fd]))
		{
			if (!(tmp = (*line) ? ft_strjoin(*line, s[fd]) : ft_strdup(s[fd])))
				return (-1);
			s[fd] = new_str(s[fd], NULL);
			*line = new_str(*line, tmp);
			return (0);
		}
	}
	free(s[fd]);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *s[FD_SIZE];
	char		*buf;
	char		*tmp;
	int			rs;

	if (BUFFER_SIZE <= 0 || !line || !(*line = ft_strdup("")) || fd < 0 ||
		(rs = read(fd, NULL, 0) < 0) ||
		!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_bufs(*line, NULL, -1));
	while ((rs = read(fd, buf, BUFFER_SIZE)))
	{
		if (rs == -1)
			return (free_bufs(*line, buf, -1));
		buf[rs] = '\0';
		if (!(tmp = (s[fd]) ? ft_strjoin(s[fd], buf) : ft_strdup(buf)))
			return (free_bufs(*line, buf, -1));
		s[fd] = new_str(s[fd], tmp);
		free(buf);
		if (ft_strchr(s[fd], '\n'))
			break ;
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (free_bufs(*line, s[fd], -1));
	}
	(rs == 0) ? free(buf) : 0;
	return (free_bufs(*line, s[fd], make_next_line(s, line, fd)));
}
