/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_calcul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:24:41 by thallard          #+#    #+#             */
/*   Updated: 2020/12/22 11:51:51 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_init_raycasting_var(t_all *ray, int x, t_mlx_info *info)
{
	double		save_x;
	double		save_y;

	ray->hit = 0;
	ray->cam = 2 * x / (double)info->w - 1;
	ray->ray_x = ray->dir_x + ray->plane_x * ray->cam;
	ray->ray_y = ray->dir_y + ray->plane_y * ray->cam;
	ray->map_x = (int)ray->player_x;
	ray->map_y = (int)ray->player_y;
	save_x = (ray->ray_x == 0) ? 1 : fabs(1 / ray->ray_x);
	save_y = (ray->ray_y == 0) ? 1 : fabs(1 / ray->ray_y);
	ray->delta_x = (ray->ray_y == 0) ? 0 : save_x;
	ray->delta_y = (ray->ray_x == 0) ? 0 : save_y;
	return (1);
}

void	ft_calculate_step_sidedest(t_all *ray)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (ray->player_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - ray->player_x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (ray->player_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - ray->player_y) * ray->delta_y;
	}
}

void	ft_check_ray_hit_wall(t_all *ray, t_mlx_info *info)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			ray->pdv = ray->ray_x > 0 ? 1 : 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			ray->pdv = ray->ray_y > 0 ? 2 : 3;
		}
		if (info->map[ray->map_x][ray->map_y] == 1)
			ray->hit = 1;
	}
}

double	ft_last_calcul_before_render(t_all *ray, t_mlx_info *info, int x)
{
	double	wall_x;

	if (ray->side == 0)
		ray->w_d = (ray->map_x - ray->player_x +
		(1 - ray->step_x) / 2) / ray->ray_x;
	else
		ray->w_d = (ray->map_y - ray->player_y +
		(1 - ray->step_y) / 2) / ray->ray_y;
	if (ray->side == 0)
		wall_x = ray->player_y + ray->w_d * ray->ray_y;
	else
		wall_x = ray->player_x + ray->w_d * ray->ray_x;
	wall_x -= floor((wall_x));
	ray->line_h = (int)(info->h / ray->w_d);
	ray->d_s = ray->line_h * -1 / 2 + info->h / 2;
	ray->d_e = ray->line_h / 2 + info->h / 2;
	if (ray->d_s < 0)
		ray->d_s = 0;
	if (ray->d_e >= info->h)
		ray->d_e = info->h - 1;
	info->sprite->z_buf[x] = ray->w_d;
	return (wall_x);
}

void	ft_print_textures(t_all *r, t_mlx_info *i, int x, double wall_x)
{
	int		t_x;
	int		t_y;
	double	step;
	double	text_pos;
	int		j;

	j = -1;
	t_x = (int)(wall_x * (double)i->t_w);
	if (r->side == 0 && r->ray_x > 0)
		t_x = i->t_w - t_x - 1;
	if (r->side == 1 && r->ray_y < 0)
		t_x = i->t_w - t_x - 1;
	step = 1.0 * i->t_h / r->line_h;
	text_pos = (r->d_s - i->h / 2 + r->line_h / 2) * step;
	while (++j < r->d_s)
		i->int_img[j * i->w + x] = ((long)i->c_color[2] + i->c_color[1] * 16 * 16 + 16 * 16 * 16 * 16 * i->c_color[0]);
	while (r->d_s < r->d_e)
	{
		if ((int)text_pos > i->t_h - 1)
			t_y = i->t_h - 1;
		else
			t_y = text_pos;
		text_pos += step;
		i->int_img[r->d_s++ * i->w + x] = i->text[r->pdv][i->t_h * t_y + t_x];
	}
	while (r->d_e < i->h)
		i->int_img[r->d_e++ * i->w + x] = ((long)i->f_color[2] + i->f_color[1] * 16 * 16 + 16 * 16 * 16 * 16 * i->f_color[0]);
}
