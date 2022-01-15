/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:34:38 by                   #+#    #+#             */
/*   Updated: 2022/01/16 02:22:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_anim {
	void	*p0;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*p5;
	void	*e0;
	void	*e1;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*e5;
	void	*c0;
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
	void	*c5;
}	t_anim;

typedef struct s_mlx {
	void	*m;
	void	*w;
}	t_mlx;

typedef struct s_players {
	int		steps;
	int		count;
	int		person_count;
	int		score;
	int		max_score;
	int		pos_y;
	int		pos_x;
}	t_play;

typedef struct s_push {
	t_mlx	m;
	t_play	pl;
	t_anim	an;
	char	**map;
	char	*line;
	char	*ret;
	void	*c;
	void	*w;
	void	*f;
	void	*p;
	void	*ex;
	void	*e1;
	void	*e2;
	int		time;
	int		a;
	int		fd;
	int		k;
	int		l;
	int		h;
	int		i;
	int		j;
	int		map_height;
	int		map_length;
}	t_push;

int		get_next_line(char **line, int fd);
void	ft_error(char *str, int fd);
void	ft_perror(char *str);

void	check_map(t_push *p, int i, int j);
void	check_args(int argc, char **argv);
void	init_map2(t_push *p);

int		moves(int keycode, t_push *p);
void	ft_go(t_push *p);
void	ft_back(t_push *p);
void	ft_left(t_push *p);
void	ft_right(t_push *p);
int		ft_exit(void *param);

void	render(t_push *p);

void	add_enemy(t_push *p);
void	enemy(t_push *p);
void	enemy1(t_push *p);
int		animation(t_push *p);
void	init_animation(t_push *p);
void	print_moves(t_push *p);

#endif
