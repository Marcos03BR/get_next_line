/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarranq <mbarranq@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:49:39 by mbarranq          #+#    #+#             */
/*   Updated: 2024/10/09 16:30:18 by mbarranq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_from_fd(int fd, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		free(buffer);
		return (-1);
	}
	buffer[*bytes_read] = '\0';
	return (0);
}

static int	read_and_store(int fd, char **remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr(*remainder, '\n') && bytes_read != 0)
	{
		if (read_from_fd(fd, buffer, &bytes_read) == -1)
			return (-1);
		temp = ft_strjoin_free(*remainder, buffer);
		if (!temp)
		{
			free(buffer);
			return (-1);
		}
		free(*remainder);
		*remainder = temp;
	}
	free(buffer);
	return (0);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*temp;
	size_t	len;

	len = 0;
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = ft_substr(*remainder, 0, len);
	if (!line)
		return (NULL);
	temp = ft_strdup(*remainder + len);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(*remainder);
	*remainder = temp;
	return (line);
}

static void	cleanup_remainder(char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*remainder[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_and_store(fd, &remainder[fd]) == -1)
	{
		cleanup_remainder(&remainder[fd]);
		return (NULL);
	}
	if (!remainder[fd] || *remainder[fd] == '\0')
	{
		cleanup_remainder(&remainder[fd]);
		return (NULL);
	}
	line = extract_line(&remainder[fd]);
	if (!line)
		cleanup_remainder(&remainder[fd]);
	return (line);
}
