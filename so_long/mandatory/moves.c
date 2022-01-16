/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:48 by                   #+#    #+#             */
/*   Updated: 2022/01/16 17:58:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	ft_exit(void *param)
{
	if (param)
		ft_putstr_fd(param, 2);
	exit(0);
}

void	ft_move(t_push *p, int y, int x, int key)
{
	if (p->map[y][x] == 'C' || p->map[y][x] == '0')
	{
		if (p->map[y][x] == 'C')
			p->pl.score++;
		p->map[y][x] = 'P';
		if (key == 13)
			p->map[p->pl.pos_y--][x] = '0';
		else if (key == 1)
			p->map[p->pl.pos_y++][x] = '0';
		else if (key == 0)
			p->map[y][p->pl.pos_x--] = '0';
		else if (key == 2)
			p->map[y][p->pl.pos_x++] = '0';
		printf("Moves: %d\n", ++p->pl.steps);
		render(p);
	}
	if (p->map[y][x] == 'E'
		&& p->pl.score == p->pl.max_score)
		ft_error("You won!\n", 1);
}

int	moves(int keycode, t_push *p)
{
	if (keycode == 13)
		ft_move(p, p->pl.pos_y - 1, p->pl.pos_x, keycode);
	else if (keycode == 1)
		ft_move(p, p->pl.pos_y + 1, p->pl.pos_x, keycode);
	else if (keycode == 0)
		ft_move(p, p->pl.pos_y, p->pl.pos_x - 1, keycode);
	else if (keycode == 2)
		ft_move(p, p->pl.pos_y, p->pl.pos_x + 1, keycode);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
