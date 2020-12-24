/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:04 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 13:10:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/libft.h"
#include "includes/cub3d.h"

int		loop_game(t_all *ray)
{
	ft_move_forward(ray);
	ft_rotate_player(ray);
	ft_move_right_and_left(ray);
	ft_print_raycasting(ray, ray->infos, ray->infos->sprite);
	return (1);
}

int		ft_print_raycasting(t_all *ray, t_mlx_info *info, t_sprite *s)
{
	int		x;
	double	wall_x;
	
	if (info->img)
		mlx_destroy_image(info->mlx_ptr, info->img);
	info->img = mlx_new_image(info->mlx_ptr, info->w, info->h);
	info->int_img = (int *)mlx_get_data_addr(info->img, &x, &x, &x);
	x = -1;
	while (++x < info->w)
	{
		if (!(ft_init_raycasting_var(ray, x, info)))
			return ((info->error = -3) + 3);
		ft_calculate_step_sidedest(ray);
		ft_check_ray_hit_wall(ray, info);
		wall_x = ft_last_calcul_before_render(ray, info, x);
		ft_print_textures(ray, info, x, wall_x);
	}
	x = -1;
	ft_sort_distance_sprites(s, ray);
	while (s->sprites[++x] != 0)
	{	
		ft_calcul_sprites(ray, info, s, x);
		ft_print_sprites(ray, info, s, 0);
	}
	ft_print_sprites(ray, info, s, 0);
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx_info	i;
	t_all		ray;
	t_movements	mov;
	t_sprite	sprite;

	ft_init_flags_movements(&mov);
	ft_init_flags(&i, &sprite);
	i.mlx_ptr = mlx_init();
	if (argc != 2 || !ft_check_map(argv[1], &i, 0, 0))
		return (ft_print_errors(0, &i));
	ft_init_flags_raycasting(&ray, &i, &mov);
	ft_set_orientation(&ray, &i);
	if (!(ft_print_raycasting(&ray, &i, ray.infos->sprite)))
		return (ft_print_errors(0, &i));
	mlx_hook(i.mlx_win, 02, 1L<<0, key_press, &ray);
	mlx_hook(i.mlx_win, 03, 1L<<1, key_release, &ray);
	mlx_hook(i.mlx_win, 17, 1L<<1, ft_exit_program, &ray);
	mlx_loop_hook(i.mlx_ptr, loop_game, &ray);
	
	mlx_loop(i.mlx_ptr);
	return (0);
}