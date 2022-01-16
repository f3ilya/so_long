/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:44 by                   #+#    #+#             */
/*   Updated: 2022/01/16 02:04:25 by                  ###   ########.fr       */
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

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Bad arguments! Use: ./so_long maps/map.ber\n", 2);
	if (ft_strlen(argv[1]) < 5)
		ft_error("Bad arguments! Use: ./so_long maps/map.ber\n", 2);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 10))
		ft_error("Bad arguments! Use: ./so_long maps/map.ber\n", 2);
}

void	check_map(t_push *p, int i, int j)
{
	if (p->map[i][0] && (p->map[i][0] != '1'
		|| p->map[i][p->map_length - 1] != '1'))
		ft_error("Bad map! The map is not surrounded by walls!\n", 2);
	if (i == 0 && p->map[0][j] != '1')
		ft_error("Bad map! The map is not surrounded by walls!\n", 2);
	if (p->map[i][j] == 'P')
	{
		p->pl.pos_y = i;
		p->pl.pos_x = j;
		p->pl.person_count++;
	}
	if (p->map[i][j] != '1' && p->map[i][j] != '0'
	&& p->map[i][j] != 'E' && p->map[i][j] != 'P' && p->map[i][j] != 'C')
		ft_error("Bad map! Wrong characters!\n", 2);
	if (p->map[i][j] == 'C')
		p->pl.max_score++;
	if (p->map[i][j] == 'E')
		p->pl.count++;
}
