/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:50 by                   #+#    #+#             */
/*   Updated: 2022/01/16 02:20:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

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
	p->ret = 0;
	p->map = 0;
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
		}
	}
}

int	main(int argc, char **argv)
{
	t_push	push;

	check_args(argc, argv);
	init_struct(&push, argv);
	render(&push);
	mlx_key_hook(push.m.w, moves, &push);
	mlx_hook(push.m.w, 17, 0, ft_exit, 0);
	mlx_loop(push.m.m);
}
