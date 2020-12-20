/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:04 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 14:45:24 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/libft.h"
#include "includes/cub3d.h"

#define texWidth 256
#define texHeight 256

int ft_move_forward(t_all *ray)
{
	if (ray->mov->key_w)
	{
		if (ray->infos->map[(int)(ray->player_x + ray->dir_x * 0.13)][(int)ray->player_y] == 0)
			ray->player_x += ray->dir_x * 0.13;
		if (ray->infos->map[(int)ray->player_x][(int)(ray->player_y + ray->dir_y * 0.13)] == 0)	
			ray->player_y += ray->dir_y * 0.13;
	}
	if (ray->mov->key_a)
	{
		double olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-3.14 / 60) - ray->dir_y * sin(-3.14 / 60);
		ray->dir_y = olddir_x * sin(-3.14 / 60) + ray->dir_y * cos(-3.14 / 60);
		double oldplane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-3.14 / 60) - ray->plane_y * sin(-3.14 / 60);
		ray->plane_y = oldplane_x * sin(-3.14 / 60) + ray->plane_y * cos(-3.14 / 60);
	
	}
	if (ray->mov->key_s)
	{
		if (ray->infos->map[(int)(ray->player_x - ray->dir_x * 0.13)][(int)ray->player_y] == 0)
			ray->player_x -= ray->dir_x * 0.13;
		if (ray->infos->map[(int)ray->player_x][(int)(ray->player_y - ray->dir_y * 0.13)] == 0)	
			ray->player_y -= ray->dir_y * 0.13;
	}
	if (ray->mov->key_d)
	{
		double olddir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(3.14 / 60) - ray->dir_y * sin(3.14 / 60);
		ray->dir_y = olddir_x * sin(3.14 / 60) + ray->dir_y * cos(3.14 / 60);
		double oldplane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(3.14 / 60) - ray->plane_y * sin(3.14 / 60);
		ray->plane_y = oldplane_x * sin(3.14 / 60) + ray->plane_y * cos(3.14 / 60);
	}
	return (1);
}

int		loop_game(t_all *ray)
{
	ft_move_forward(ray);
	ft_print_raycasting(ray, ray->infos);
	return (1);
}

int		ft_print_raycasting(t_all *ray, t_mlx_info *info)
{
	int		x;
	double	wall_x;

	mlx_destroy_image(info->mlx_ptr, info->img);
	info->img = mlx_new_image(info->mlx_ptr, info->w, info->h);
	info->int_img = (int *)mlx_get_data_addr(info->img, &x, &x, &x);
	x = -1;
	while (++x < info->w)
	{
		if (!(ft_init_raycasting_var(ray, x, info)))
			return (-5);
		ft_calculate_step_sidedest(ray);
		ft_check_ray_hit_wall(ray, info);
		wall_x = ft_last_calcul_before_render(ray, info);
		ft_print_textures(ray, info, x, wall_x);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx_info	i;
	t_all		ray;
	t_movements	mov;

	ft_init_flags_movements(&mov);
	ft_init_flags(&i);
	i.mlx_ptr = mlx_init();
	if (argc != 2 || !ft_check_map(argv[1], &i))
		return (ft_print_errors(-1));
	ft_init_flags_raycasting(&ray, &i, &mov);
	ft_print_raycasting(&ray, &i);
	mlx_hook(i.mlx_win, 02, 1L<<0, key_press, &ray);
	mlx_hook(i.mlx_win, 03, 1L<<1, key_release, &ray);
	mlx_loop_hook(i.mlx_ptr, loop_game, &ray);
	
	mlx_loop(i.mlx_ptr);
	return (0);
}