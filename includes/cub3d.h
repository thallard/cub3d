/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:41:55 by thallard          #+#    #+#             */
/*   Updated: 2020/12/18 18:34:22 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D
# define FT_CUB3D

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_mlx_info
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			width;
	int			height;
	int			*texture[4];
	int			t_w;
	int			t_h;
	int			*map[256];
}				t_mlx_info;

typedef struct	s_movements
{
	int			key_d;
	int			key_a;
	int			key_s;
	int			key_w;
}				t_movements;

typedef struct	s_all
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			drawEnd;
	int			drawStart;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	t_movements	*mov;
	t_mlx_info	*infos;
}				t_all;


int		ft_affiche_mes_couilles(t_all *ray, t_mlx_info *info);

int		ft_fill_resolution(char *line, t_mlx_info *info);
int		ft_check_map(char *map_name, t_mlx_info *info);
int		ft_fill_path_texture(char *line, t_mlx_info *info, int nb_paths);


void	ft_init_flags(t_mlx_info *info);
void	ft_init_flags_raycasting(t_all *ray, t_mlx_info *info, t_movements *mov);
void	ft_init_flags_movements(t_movements *mov);
int		ft_get_orientation(char *line);
int		ft_print_errors(int error);
int		ft_parcours_map(t_mlx_info *info, int fd);

int		ft_move_forward(t_all *ray);

int		key_release(int keycode, t_all *ray);
int		key_press(int keycode, t_all *ray);


#endif