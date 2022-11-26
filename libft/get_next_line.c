/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:52:54 by cnascime          #+#    #+#             */
/*   Updated: 2022/10/18 18:54:24 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The static function keeps whatever value is passed onto it until the program
is closed. It is by default initialised at 0, if not declared otherwise. */
char	*get_next_line(int fd)
{	
	char		*line;
	static char	*temp[4096] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = reader(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = reaper(temp[fd]);
	temp[fd] = rescuer(temp[fd]);
	return (line);
}

char	*reader(int fd, char *temp)
{
	char	*auxiliary;
	int		bytes_read;

	auxiliary = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!auxiliary)
		return (NULL);
	bytes_read = 1;
	if (!auxiliary || bytes_read < 0)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, auxiliary, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(auxiliary);
			return (NULL);
		}
		auxiliary[bytes_read] = '\0';
		temp = ft_strjoin(temp, auxiliary);
	}
	free(auxiliary);
	return (temp);
}

char	*reaper(char *temp)
{
	char	*line;
	int		i;

	if (!*temp)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rescuer(char *temp)
{
	char	*auxiliary;
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	auxiliary = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!auxiliary)
		return (NULL);
	i++;
	j = 0;
	while (temp[i] != '\0')
		auxiliary[j++] = temp[i++];
	auxiliary[j] = '\0';
	free(temp);
	return (auxiliary);
}
