/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:16 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/17 16:08:29 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*free_stor(char **storage)
{
	free (*storage);
	*storage = NULL;
	return (NULL);
}

char	*new_storage(char *storage, char *line)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	if (!line)
		return (NULL);
	temp = ft_calloc((ft_strlen(storage) - ft_strlen(line) + 2), sizeof(char));
	i = ft_strlen(line);
	while (storage[i])
	{
		temp[j] = storage[i];
		i++;
		j++;
	}
	free(storage);
	storage = NULL;
	temp[j] = 0;
	return (temp);
}

char	*new_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		i--;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		free_stor(&storage);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_line(char *storage, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		n_bytes;

	n_bytes = 1;
	buffer[0] = 0;
	if (!storage)
	{
		storage = ft_calloc(1, 1);
		if (!storage)
			return (NULL);
	}
	while (n_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes < 0)
			free_stor(&storage);
		buffer[n_bytes] = 0;
		temp = ft_strjoin(storage, buffer);
		free(storage);
		if (!temp)
			return (NULL);
		storage = temp;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = read_line(storage, fd);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
	}
	storage = new_storage(storage, line);
	return (line);
}
