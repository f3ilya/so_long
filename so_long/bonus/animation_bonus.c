/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:35:12 by                   #+#    #+#             */
/*   Updated: 2022/01/16 01:52:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	init_animation(t_push *p)
{
	p->an.p0 = mlx_xpm_file_to_image(p->m.m, "texture/p0.xpm", &p->a, &p->a);
	p->an.p1 = mlx_xpm_file_to_image(p->m.m, "texture/p1.xpm", &p->a, &p->a);
	p->an.p2 = mlx_xpm_file_to_image(p->m.m, "texture/p2.xpm", &p->a, &p->a);
	p->an.p3 = mlx_xpm_file_to_image(p->m.m, "texture/p3.xpm", &p->a, &p->a);
	p->an.p4 = mlx_xpm_file_to_image(p->m.m, "texture/p4.xpm", &p->a, &p->a);
	p->an.p5 = mlx_xpm_file_to_image(p->m.m, "texture/p5.xpm", &p->a, &p->a);
	p->an.e0 = mlx_xpm_file_to_image(p->m.m, "texture/e0.xpm", &p->a, &p->a);
	p->an.e1 = mlx_xpm_file_to_image(p->m.m, "texture/e1.xpm", &p->a, &p->a);
	p->an.e2 = mlx_xpm_file_to_image(p->m.m, "texture/e2.xpm", &p->a, &p->a);
	p->an.e3 = mlx_xpm_file_to_image(p->m.m, "texture/e3.xpm", &p->a, &p->a);
	p->an.e4 = mlx_xpm_file_to_image(p->m.m, "texture/e4.xpm", &p->a, &p->a);
	p->an.e5 = mlx_xpm_file_to_image(p->m.m, "texture/e5.xpm", &p->a, &p->a);
	p->an.c0 = mlx_xpm_file_to_image(p->m.m, "texture/c0.xpm", &p->a, &p->a);
	p->an.c1 = mlx_xpm_file_to_image(p->m.m, "texture/c1.xpm", &p->a, &p->a);
	p->an.c2 = mlx_xpm_file_to_image(p->m.m, "texture/c2.xpm", &p->a, &p->a);
	p->an.c3 = mlx_xpm_file_to_image(p->m.m, "texture/c3.xpm", &p->a, &p->a);
	p->an.c4 = mlx_xpm_file_to_image(p->m.m, "texture/c4.xpm", &p->a, &p->a);
	p->an.c5 = mlx_xpm_file_to_image(p->m.m, "texture/c5.xpm", &p->a, &p->a);
}

void	anim_pers(t_push *p, int key)
{
	if (p->pl.person_count == 0 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p0, p->j * 40, p->i * 40);
	else if (p->pl.person_count == 1 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p1, p->j * 40, p->i * 40);
	else if (p->pl.person_count == 2 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p2, p->j * 40, p->i * 40);
	else if (p->pl.person_count == 3 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p3, p->j * 40, p->i * 40);
	else if (p->pl.person_count == 4 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p4, p->j * 40, p->i * 40);
	else if (p->pl.person_count == 5 && key == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.p5, p->j * 40, p->i * 40);
	else if (p->pl.count == 0 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e0, p->j * 40, p->i * 40);
	else if (p->pl.count == 1 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e1, p->j * 40, p->i * 40);
	else if (p->pl.count == 2 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e2, p->j * 40, p->i * 40);
	else if (p->pl.count == 3 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e3, p->j * 40, p->i * 40);
	else if (p->pl.count == 4 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e4, p->j * 40, p->i * 40);
	else if (p->pl.count == 5 && key == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.e5, p->j * 40, p->i * 40);
}

void	anim_pers1(t_push *p)
{
	if (p->a == 0)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c0, p->j * 40, p->i * 40);
	else if (p->a == 1)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c1, p->j * 40, p->i * 40);
	else if (p->a == 2)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c2, p->j * 40, p->i * 40);
	else if (p->a == 3)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c3, p->j * 40, p->i * 40);
	else if (p->a == 4)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c4, p->j * 40, p->i * 40);
	else if (p->a == 5)
		mlx_put_image_to_window(p->m.m, p->m.w, p->an.c5, p->j * 40, p->i * 40);
}

int	animation(t_push *p)
{
	p->i = -1;
	while (p->map[++p->i])
	{
		p->j = -1;
		while (p->map[p->i][++p->j])
		{
			if (p->map[p->i][p->j] == 'P')
				anim_pers(p, 1);
			else if (p->map[p->i][p->j] == 'A' || p->map[p->i][p->j] == 'T')
				anim_pers(p, 2);
			else if (p->map[p->i][p->j] == 'C')
				anim_pers1(p);
		}
	}
	if (p->a++ > 5)
		p->a = 0;
	if (p->pl.count++ > 5)
		p->pl.count = 0;
	if (p->pl.person_count++ > 5)
		p->pl.person_count = 0;
	usleep(100000);
	enemy(p);
	enemy1(p);
	return (1);
}

void	print_moves(t_push *p)
{
	p->line = ft_itoa(p->pl.steps);
	mlx_string_put(p->m.m, p->m.w, 5, 5, 0x000000, "Moves: ");
	mlx_string_put(p->m.m, p->m.w, 65, 5, 0x000000, p->line);
}
