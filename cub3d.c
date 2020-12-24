/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:04 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 16:21:22 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
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

int		ft_print_raycasting(t_all *ray, t_mlx_info *i, t_sprite *s)
{
	int		x;

	if (i->img)
		mlx_destroy_image(i->mlx_ptr, i->img);
	i->img = mlx_new_image(i->mlx_ptr, i->w, i->h);
	i->int_img = (int *)mlx_get_data_addr(i->img, &x, &x, &x);
	x = -1;
	while (++x < i->w)
	{
		if (!(ft_init_raycasting_var(ray, x, i)))
			return ((i->error = -3) + 3);
		ft_calculate_step_sidedest(ray);
		ft_check_ray_hit_wall(ray, i);
		ft_print_textures(ray, i, x, ft_last_calcul_before_render(ray, i, x));
	}
	x = -1;
	ft_sort_distance_sprites(s, ray);
	while (s->sprites[++x] != 0)
	{
		ft_calcul_sprites(ray, i, s, x);
		ft_print_sprites(ray, i, s, 0);
	}
	ft_print_sprites(ray, i, s, 0);
	mlx_put_image_to_window(i->mlx_ptr, i->mlx_win, i->img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx_info	i;
	t_all		ray;
	t_movements	mov;
	t_sprite	sprite;
	t_bmp		bmp;

	ft_init_flags_movements(&mov);
	ft_init_flags(&i, &sprite);
	i.mlx_ptr = mlx_init();
	if ((argc != 2 && argc != 3) || !ft_check_map(argv[1], &i, 0, 0))
		return (ft_print_errors(0, &i));
	ft_init_flags_raycasting(&ray, &i, &mov, &bmp);
	ft_set_orientation(&ray, &i);
	if (!(ft_print_raycasting(&ray, &i, ray.infos->sprite)))
		return (ft_print_errors(0, &i));
	if (argc == 3)
		ft_init_bmp(&ray, &i, argv);
	mlx_hook(i.mlx_win, 02, 1L << 0, key_press, &ray);
	mlx_hook(i.mlx_win, 03, 1L << 1, key_release, &ray);
	mlx_hook(i.mlx_win, 17, 1L << 1, ft_exit_program, &ray);
	mlx_loop_hook(i.mlx_ptr, loop_game, &ray);
	mlx_loop(i.mlx_ptr);
	return (0);
}
