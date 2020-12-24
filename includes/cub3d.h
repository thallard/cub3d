/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:41:55 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 17:01:22 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

# define SPEED 0.15
# define ROTATE 0.10

typedef struct	s_bmp
{
	char		header[54];
	int			fd;
	int			w;
	int			height;
	int			bytes_number;
	int			width_bytes;
	int			image_s;
	int			bytes_s;
	int			file_s;
	int			header_s;
	int			biplanes;
}				t_bmp;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		s_x;
	double		s_y;
	int			*int_spr;
	double		inv_d;
	double		t_y;
	double		t_x;
	int			s_spr_x;
	int			s_h;
	int			s_dsx;
	int			s_dex;
	int			s_dsy;
	int			s_dey;
	int			s_width;
	double		z_buf[3660];
	int			*sprites[100];
	int			*sorted_sprites[100];
	int			s_path;
}				t_sprite;

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
	int			error;
	int			f_color[3];
	int			c_color[3];
	int			s_w;
	int			s_h;
	double		player_x;
	double		player_y;
	char		orientation;
	t_sprite	*sprite;
	t_bmp		*bmp;
}				t_mlx_info;

typedef struct	s_movements
{
	int			key_d;
	int			key_a;
	int			key_s;
	int			key_w;
	int			key_al;
	int			key_ar;
	int			key_escape;
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
	t_bmp		*bmp;
}				t_all;

/*
** Setters
*/
void			ft_init_flags(t_mlx_info *info, t_sprite *sprites);
void			ft_init_flags_raycasting(t_all *ray, t_mlx_info *info,
t_movements *mov, t_bmp *bmp);
void			ft_init_flags_movements(t_movements *mov);

/*
** Rendering part (raycasting)
*/
int				ft_print_raycasting(t_all *ray, t_mlx_info *info, t_sprite *s);
int				ft_init_raycasting_var(t_all *ray, int x, t_mlx_info *info);
void			ft_calculate_step_sidedest(t_all *ray);
void			ft_check_ray_hit_wall(t_all *ray, t_mlx_info *info);
double			ft_last_calcul_before_render(t_all *ray, t_mlx_info *i, int x);
void			ft_print_textures(t_all *ray, t_mlx_info *i, int x, double w);
void			ft_calcul_sprites(t_all *r, t_mlx_info *i, t_sprite *s, int n);
void			ft_print_sprites(t_all *ray, t_mlx_info *i, t_sprite *s, int x);
void			ft_sort_distance_sprites(t_sprite *s, t_all *r);

/*
** Movements part (player)
*/
void			ft_move_forward(t_all *r);
void			ft_rotate_player(t_all *r);
int				key_release(int keycode, t_all *ray);
int				key_press(int keycode, t_all *ray);
void			ft_move_right_and_left(t_all *r);

/*
**	Map part (Resolution, textures, colors and map)
*/
int				ft_fill_map(t_mlx_info *i, char **str, int rows, int k);
int				ft_parcours_map(t_mlx_info *info, char *line);
int				ft_malloc_map(t_mlx_info *info, char **str);
int				ft_map_contains(char *line, t_mlx_info *info);
int				ft_fill_floor_color(char *line, t_mlx_info *i, int c, int nb);
int				ft_fill_ceiling_color(char *line, t_mlx_info *i, int c, int nb);
int				ft_fill_resolution(char *line, t_mlx_info *info);
int				ft_check_map(char *map_name, t_mlx_info *info, int m, int p);
int				ft_fill_path_texture(char *line, t_mlx_info *info, int nb);
int				ft_check_walls_map(t_mlx_info *i, int rows, char **str);
int				ft_check_map_zero(t_mlx_info *i, char **str, int k, int j);
int				check_map(char *line, t_mlx_info *info, char **map, int m);
int				ft_check_content_map(char *line, t_mlx_info *info, int paths);
int				ft_fill_sprite(char *line, t_mlx_info *info);
int				ft_set_spawn(t_mlx_info *info, int y, int x, char c);
void			ft_fill_sprites_map(t_mlx_info *i, char **str);
void			ft_checker_resolution(t_mlx_info *info);
int				ft_get_orientation(char *line);
int				ft_check_character_map(char *line, t_mlx_info *i);

/*
** Screenshot part
*/
void			ft_start_init_bmp(t_all *a, t_mlx_info *i);
void			ft_init_bmp(t_all *a, t_mlx_info *i, char **argv, int argc);
void			ft_fill_bmp_header(t_all *a);
void			ft_write_screenshot_in_bmp(t_all *a);

/*
** Utils part
*/
int				ft_exit_program(t_all *ray);
int				get_spawns(char **str);
int				check_ext(char *str);
void			ft_set_orientation(t_all *r, t_mlx_info *i);
void			ft_free_str_map(char **str, int rows);
int				ft_print_errors(int error, t_mlx_info *i);
void			ft_bzero(void *pointer, int size);
#endif
