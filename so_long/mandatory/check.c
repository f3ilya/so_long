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

void	init_map2(t_push *p)
{
	p->i = -1;
	p->map_length = (int)ft_strlen(p->map[0]);
	while (p->map[++p->i])
	{
		if (p->map_length != (int)ft_strlen(p->map[p->i]))
			ft_error("Bad map! This is not a rectangle!\n", 2);
		p->j = -1;
		while (p->map[p->i][++p->j])
			check_map(p, p->i, p->j);
	}
	p->map_height = p->i;
	if (ft_strncmp(p->map[p->i - 1], p->map[0], p->map_length))
		ft_error("Bad map! The map is not surrounded by walls!\n", 2);
	if (p->map_length == p->map_height)
		ft_error("Bad map! This is not a rectangle\n", 2);
	if (p->pl.person_count != 1 || p->pl.max_score < 1 || p->pl.count < 1)
		ft_error("Bad map! Wrong characters!\n", 2);
}
