/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:16:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 19:23:45 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	ft_init_flags(t_mlx_info *info)
{
	info->mlx_ptr = NULL;
	info->mlx_win = NULL;
	info->img = NULL;
	info->w = 0;
	info->h = 0;
	info->error = 0;
	info->c_color[0] = 0;
	info->c_color[1] = 0;
	info->c_color[2] = 0;
	info->f_color[0] = 0;
	info->f_color[1] = 0;
	info->f_color[2] = 0;
}

void	ft_init_flags_raycasting(t_all *ray, t_mlx_info *info, t_movements *mov)
{
	ray->player_x = 2;
	ray->player_y = 2;
	ray->dir_x = 1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.50;
	ray->cam = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->w_d = 0;
	ray->d_e = 0;
	ray->d_s = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->infos = info;
	ray->mov = mov;
}

void	ft_init_flags_movements(t_movements *mov)
{
	mov->key_a = 0;
	mov->key_w = 0;
	mov->key_s = 0;
	mov->key_d = 0;
	mov->key_ar = 0;
	mov->key_al = 0;
}

int		ft_print_errors(int error, t_mlx_info *i)
{
	if (error == -1)
		return (ft_printf("Error %d : Map error.\n", error));
	if (i->error == -5)
		return (ft_printf("Error %d : Wrong resolution in config file.\n", i->error));
	if (i->error == -6)
		return (ft_printf("Error %d : Wrong path for a texture.\n", i->error));
	if (i->error == -7)
		return (ft_printf("Error %d : Invalid format map.\n", i->error));
	if (i->error == -8)
		return (ft_printf("Error %d : Invalid color floor/ceiling.\n", i->error));
	return (0);
}