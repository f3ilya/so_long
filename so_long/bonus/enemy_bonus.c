/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:35:16 by                   #+#    #+#             */
/*   Updated: 2022/01/16 01:35:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	add_enemy(t_push *p)
{
	p->fd = 0;
	p->i = p->map_height - 1;
	while (--p->i > 0)
	{
		p->j = p->map_length - 1;
		while (--p->j > 0)
		{
			if (p->map[p->i][p->j] == '0')
			{
				if (p->fd == 0 && p->map[p->i][p->j - 1] == '0')
				{
					p->map[p->i][p->j - 1] = 'A';
					p->i -= 3;
					p->fd++;
				}
				else if (p->fd == 1 && p->map[p->i][p->j - 1] == '0')
				{
					p->map[p->i][p->j] = 'T';
					p->fd = 2;
					break ;
				}
			}
		}
	}
}

void	go_enemy1(t_push *p, int y, int x)
{
	if (p->l == 0 && (p->map[y][x + 1] == '0' || p->map[y][x + 1] == 'P'))
	{
		if (p->map[y][x + 1] == 'P')
			ft_error("Game over!\n", 1);
		if (p->map[y][x + 2] != '0' && p->map[y][x + 2] != 'P')
			p->l = 1;
		p->map[y][x + 1] = 'A';
		p->map[y][x] = '0';
	}
	else if (p->l == 1 && (p->map[y][x - 1] == '0' || p->map[y][x - 1] == 'P'))
	{
		if (p->map[y][x - 1] == 'P')
			ft_error("Game over!\n", 1);
		if (p->map[y][x - 2] != '0' && p->map[y][x - 2] != 'P')
			p->l = 0;
		p->map[y][x - 1] = 'A';
		p->map[y][x] = '0';
	}
}

void	go_enemy2(t_push *p, int y, int x)
{
	if (p->h == 0 && (p->map[y + 1][x] == '0' || p->map[y + 1][x] == 'P'))
	{
		if (p->map[y + 1][x] == 'P')
			ft_error("Game over!\n", 1);
		if (p->map[y + 2][x] != '0' && p->map[y + 2][x] != 'P')
			p->h = 1;
		p->map[y + 1][x] = 'T';
		p->map[y][x] = '0';
	}
	else if (p->h == 1 && (p->map[y - 1][x] == '0' || p->map[y - 1][x] == 'P'))
	{
		if (p->map[y - 1][x] == 'P')
			ft_error("Game over!\n", 1);
		if (p->map[y - 2][x] != '0' && p->map[y - 2][x] != 'P')
			p->h = 0;
		p->map[y - 1][x] = 'T';
		p->map[y][x] = '0';
	}
}

void	enemy(t_push *p)
{
	p->time++;
	p->i = -1;
	if (p->time++ % 10 == 0)
	{
		while (p->map[++p->i])
		{
			p->j = -1;
			while (p->map[p->i][++p->j])
			{
				if (p->map[p->i][p->j] == 'A')
				{
					go_enemy1(p, p->i, p->j);
					render(p);
					return ;
				}
			}
		}
	}
}

void	enemy1(t_push *p)
{
	p->time++;
	p->i = -1;
	if (p->time % 10 == 0)
	{
		while (p->map[++p->i])
		{
			p->j = -1;
			while (p->map[p->i][++p->j])
			{
				if (p->map[p->i][p->j] == 'T')
				{
					go_enemy2(p, p->i, p->j);
					render(p);
					return ;
				}
			}
		}
	}
}
