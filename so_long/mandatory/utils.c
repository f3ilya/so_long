/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:57 by                   #+#    #+#             */
/*   Updated: 2022/01/16 01:35:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	get_next_line(char **line, int fd)
{
	char	*buffer;
	char	join;
	int		i;
	int		bytes_buf;

	i = 0;
	buffer = (char *) malloc(10000);
	if (!buffer)
		return (-1);
	bytes_buf = read(fd, &join, 1);
	while (bytes_buf && join != '\n' && join != '\0')
	{
		if (join != '\n' && join != '\0')
			buffer[i] = join;
		i++;
		bytes_buf = read(fd, &join, 1);
	}
	buffer[i] = '\0';
	*line = buffer;
	free(buffer);
	return (bytes_buf);
}

void	ft_error(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
