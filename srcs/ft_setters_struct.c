/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:16:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 14:19:04 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	ft_init_flags(t_mlx_info *info, t_sprite *sprites)
{
	info->mlx_ptr = NULL;
	info->mlx_win = NULL;
	info->img = NULL;
	info->w = 0;
	info->h = 0;
	info->error = 0;
	info->text[0] = NULL;
	info->text[1] = NULL;
	info->text[2] = NULL;
	info->text[3] = NULL;
	info->c_color[0] = 0;
	info->c_color[1] = 0;
	info->c_color[2] = 0;
	info->f_color[0] = 0;
	info->f_color[1] = 0;
	info->f_color[2] = 0;
	info->sprite = sprites;
	info->sprite->s_path = 0;
	info->orientation = 0;
}

void	ft_init_flags_raycasting(t_all *ray, t_mlx_info *info,
t_movements *mov, t_bmp *bmp)
{
	ray->player_x = info->player_x;
	ray->player_y = info->player_y;
	ray->dir_x = 1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
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
	ray->bmp = bmp;
}

void	ft_init_flags_movements(t_movements *mov)
{
	mov->key_a = 0;
	mov->key_w = 0;
	mov->key_s = 0;
	mov->key_d = 0;
	mov->key_ar = 0;
	mov->key_al = 0;
	mov->key_escape = 0;
}
