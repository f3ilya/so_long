/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:48 by                   #+#    #+#             */
/*   Updated: 2022/01/16 02:04:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	ft_go(t_push *p)
{
	if (p->map[p->pl.pos_y - 1][p->pl.pos_x] == 'C'
		|| p->map[p->pl.pos_y - 1][p->pl.pos_x] == '0')
	{
		if (p->map[p->pl.pos_y - 1][p->pl.pos_x] == 'C')
			p->pl.score++;
		p->map[p->pl.pos_y - 1][p->pl.pos_x] = 'P';
		p->map[p->pl.pos_y--][p->pl.pos_x] = '0';
		printf("Moves: %d\n", ++p->pl.steps);
		render(p);
	}
	if (p->map[p->pl.pos_y - 1][p->pl.pos_x] == 'E'
		&& p->pl.score == p->pl.max_score)
		ft_error("You won!\n", 1);
}

void	ft_back(t_push *p)
{
	if (p->map[p->pl.pos_y + 1][p->pl.pos_x] == 'C'
		|| p->map[p->pl.pos_y + 1][p->pl.pos_x] == '0')
	{
		if (p->map[p->pl.pos_y + 1][p->pl.pos_x] == 'C')
			p->pl.score++;
		p->map[p->pl.pos_y + 1][p->pl.pos_x] = 'P';
		p->map[p->pl.pos_y++][p->pl.pos_x] = '0';
		printf("Moves: %d\n", ++p->pl.steps);
		render(p);
	}
	if (p->map[p->pl.pos_y + 1][p->pl.pos_x] == 'E'
		&& p->pl.score == p->pl.max_score)
		ft_error("You won!\n", 1);
}

void	ft_left(t_push *p)
{
	if (p->map[p->pl.pos_y][p->pl.pos_x - 1] == 'C'
		|| p->map[p->pl.pos_y][p->pl.pos_x - 1] == '0')
	{
		if (p->map[p->pl.pos_y][p->pl.pos_x - 1] == 'C')
			p->pl.score++;
		p->map[p->pl.pos_y][p->pl.pos_x - 1] = 'P';
		p->map[p->pl.pos_y][p->pl.pos_x--] = '0';
		printf("Moves: %d\n", ++p->pl.steps);
		render(p);
	}
	if (p->map[p->pl.pos_y][p->pl.pos_x - 1] == 'E'
		&& p->pl.score == p->pl.max_score)
		ft_error("You won!\n", 1);
}

void	ft_right(t_push *p)
{
	if (p->map[p->pl.pos_y][p->pl.pos_x + 1] == 'C'
		|| p->map[p->pl.pos_y][p->pl.pos_x + 1] == '0')
	{
		if (p->map[p->pl.pos_y][p->pl.pos_x + 1] == 'C')
			p->pl.score++;
		p->map[p->pl.pos_y][p->pl.pos_x + 1] = 'P';
		p->map[p->pl.pos_y][p->pl.pos_x++] = '0';
		printf("Moves: %d\n", ++p->pl.steps);
		render(p);
	}
	if (p->map[p->pl.pos_y][p->pl.pos_x + 1] == 'E'
		&& p->pl.score == p->pl.max_score)
		ft_error("You won!\n", 1);
}

int	ft_exit(void *param)
{
	if (param)
		ft_putstr_fd(param, 2);
	exit(0);
}
