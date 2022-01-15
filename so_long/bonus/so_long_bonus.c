/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:17 by                   #+#    #+#             */
/*   Updated: 2022/01/16 02:17:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	init_map(t_push *p, char **argv)
{
	p->fd = open(argv[1], O_RDONLY);
	if (p->fd < 0)
		ft_perror(argv[1]);
	while (get_next_line(&p->line, p->fd))
	{
		if (!p->ret)
			p->ret = ft_strdup(p->line);
		else
		{
			p->ret = ft_strjoin(p->ret, " ");
			p->ret = ft_strjoin(p->ret, p->line);
		}
	}
	if (!ft_strchr(p->ret, 'C') || !ft_strchr(p->ret, 'E')
		|| !ft_strchr(p->ret, 'P'))
		ft_error("Bad map! Wrong characters!\n", 2);
	p->map = ft_split(p->ret, ' ');
	close(p->fd);
	init_map2(p);
}

void	init_struct(t_push *p, char **argv)
{
	p->map_height = 0;
	p->map_length = 0;
	p->a = 0;
	p->h = 0;
	p->l = 0;
	p->ret = 0;
	p->map = 0;
	p->time = 0;
	p->pl.steps = 0;
	p->pl.score = 0;
	p->pl.count = 0;
	p->pl.max_score = 0;
	p->pl.person_count = 0;
	init_map(p, argv);
	p->m.m = mlx_init();
	p->m.w = mlx_new_window(p->m.m, 40 * p->map_length,
			40 * p->map_height, "so_long");
	p->f = mlx_xpm_file_to_image(p->m.m, "texture/f.xpm", &p->a, &p->a);
	p->w = mlx_xpm_file_to_image(p->m.m, "texture/w.xpm", &p->a, &p->a);
	p->p = mlx_xpm_file_to_image(p->m.m, "texture/p0.xpm", &p->a, &p->a);
	p->c = mlx_xpm_file_to_image(p->m.m, "texture/c0.xpm", &p->a, &p->a);
	p->ex = mlx_xpm_file_to_image(p->m.m, "texture/ex.xpm", &p->a, &p->a);
	p->e1 = mlx_xpm_file_to_image(p->m.m, "texture/e0.xpm", &p->a, &p->a);
	p->e2 = mlx_xpm_file_to_image(p->m.m, "texture/e0.xpm", &p->a, &p->a);
	add_enemy(p);
}

void	render(t_push *p)
{
	int	i;
	int	j;

	i = -1;
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			mlx_put_image_to_window(p->m.m, p->m.w, p->f, j * 40, i * 40);
			if (p->map[i][j] == '1')
				mlx_put_image_to_window(p->m.m, p->m.w, p->w, j * 40, i * 40);
			if (p->map[i][j] == 'P')
				mlx_put_image_to_window(p->m.m, p->m.w, p->p, j * 40, i * 40);
			if (p->map[i][j] == 'E')
				mlx_put_image_to_window(p->m.m, p->m.w, p->ex, j * 40, i * 40);
			if (p->map[i][j] == 'C')
				mlx_put_image_to_window(p->m.m, p->m.w, p->c, j * 40, i * 40);
			if (p->map[i][j] == 'A')
				mlx_put_image_to_window(p->m.m, p->m.w, p->e1, j * 40, i * 40);
			if (p->map[i][j] == 'T')
				mlx_put_image_to_window(p->m.m, p->m.w, p->e2, j * 40, i * 40);
		}
	}
	print_moves(p);
}

int	moves(int keycode, t_push *p)
{
	if (keycode == 13)
		ft_go(p);
	else if (keycode == 1)
		ft_back(p);
	else if (keycode == 0)
		ft_left(p);
	else if (keycode == 2)
		ft_right(p);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push	push;

	check_args(argc, argv);
	init_struct(&push, argv);
	init_animation(&push);
	render(&push);
	mlx_key_hook(push.m.w, moves, &push);
	mlx_loop_hook(push.m.m, animation, &push);
	mlx_hook(push.m.w, 17, 0, ft_exit, 0);
	mlx_loop(push.m.m);
	exit(EXIT_SUCCESS);
}
