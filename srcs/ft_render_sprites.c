/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:59:25 by thallard          #+#    #+#             */
/*   Updated: 2020/12/23 10:48:05 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

void	ft_calcul_sprites(t_all *ray, t_mlx_info *info, t_sprite *s)
{
	s->s_x = info->sprite->x - ray->player_x + 0.5;
	s->s_y = info->sprite->y - ray->player_y + 0.5;
	s->inv_d = 1.0 / (ray->plane_x * ray->dir_y - ray->dir_x * ray->plane_y);
	s->t_x = s->inv_d * (ray->dir_y * s->s_x - ray->dir_x * s->s_y);
	s->t_y = s->inv_d * (-ray->plane_y * s->s_x + ray->plane_x * s->s_y);
	s->s_spr_x = ((int)(info->w / 2) * (1 + s->t_x / s->t_y));
	s->s_h = abs(((int)(info->h / s->t_y)));
	s->s_dsy = -s->s_h / 2 + info->h / 2;
	if (s->s_dsy < 0)
		s->s_dsy = 0;
	s->s_dey = s->s_h / 2 + info->h / 2;
	if (s->s_dey >= info->h)
		s->s_dey = info->h - 1;
	s->s_width = abs(((int)(info->h / s->t_y)));
	s->s_dsx = -s->s_width / 2 + s->s_spr_x;
	if (s->s_dsx < 0)
		s->s_dsx = 0;
	s->s_dex = s->s_width / 2 + s->s_spr_x;
	if (s->s_dex >= info->w)
		s->s_dex = info->w - 1;
}

void	ft_print_sprites(t_all *ray, t_mlx_info *i, t_sprite *s, int x)
{
	int		y;
	int		t_x;
	int		d;
	int		t_y;

	(void)ray;
	x = s->s_dsx - 1;
	while (++x < s->s_dex)
	{
		t_x = ((int)256 * (x - (-s->s_width / 2 + s->s_spr_x))
		* i->s_w / s->s_width) / 256;
		y = s->s_dsy - 1;
		if (s->t_y > 0 && x > 0 && x < i->w && s->t_y < i->sprite->z_buf[x])
			while (++y < s->s_dey)
			{
				d = (y) * 256 - i->h * 128 + s->s_h * 128;
				t_y = ((d * i->s_h) / s->s_h) / 256;
				if ((s->int_spr[i->s_h * t_y + t_x] & 0x00FFFFFF) != 0)
					i->int_img[y * i->w + x] = s->int_spr[i->s_h * t_y + t_x];
			}
	}
}
