/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:41:55 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 14:46:22 by thallard         ###   ########lyon.fr   */
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
	int			*int_img;
	int			w;
	int			h;
	int			*text[4];
	int			t_w;
	int			t_h;
	int			**map;
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
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		cam;
	double		ray_x;
	double		ray_y;
	int			map_x;
	int			map_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		w_d;
	int			d_e;
	int			d_s;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			pdv;
	t_movements	*mov;
	t_mlx_info	*infos;
}				t_all;




int		ft_fill_resolution(char *line, t_mlx_info *info);
int		ft_check_map(char *map_name, t_mlx_info *info);
int		ft_fill_path_texture(char *line, t_mlx_info *info, int nb_paths);
int		ft_check_walls_map(t_mlx_info *i, int rows, char **str);
int		ft_check_map_zero(t_mlx_info *i, char **str, int k, int j);


void	ft_init_flags(t_mlx_info *info);
void	ft_init_flags_raycasting(t_all *ray, t_mlx_info *info, t_movements *mov);
void	ft_init_flags_movements(t_movements *mov);
int		ft_get_orientation(char *line);
int		ft_print_errors(int error);

/*
* Rendering part (raycasting)
*/
int		ft_print_raycasting(t_all *ray, t_mlx_info *info);
int		ft_init_raycasting_var(t_all *ray, int x, t_mlx_info *info);
void	ft_calculate_step_sidedest(t_all *ray);
void	ft_check_ray_hit_wall(t_all *ray, t_mlx_info *info);
double		ft_last_calcul_before_render(t_all *ray, t_mlx_info *info);
void	ft_print_textures(t_all *ray, t_mlx_info *i, int x, double wall_x);

/*
**	Map part (Resolution, textures, colors and map)
*/
int		ft_fill_map(t_mlx_info *i, char **str, int rows);
int		ft_parcours_map(t_mlx_info *info, char *line);
int		ft_malloc_map(t_mlx_info *info, char **str);

int		ft_move_forward(t_all *ray);

int		key_release(int keycode, t_all *ray);
int		key_press(int keycode, t_all *ray);


#endif