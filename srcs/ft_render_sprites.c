/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:59:25 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 16:21:11 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

void	ft_calcul_sprites(t_all *ray, t_mlx_info *info, t_sprite *s, int n)
{
	s->s_x = s->sprites[n][1] - ray->player_x + 0.5;
	s->s_y = s->sprites[n][0] - ray->player_y + 0.5;
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

void	ft_print_sprites(t_all *ray, t_mlx_info *i, t_sprite *s, int n)
{
	int		y;
	int		t_x;
	int		d;
	int		t_y;
	int		x;

	(void)n;
	(void)ray;
	x = s->s_dsx - 1;
	while (++x < s->s_dex)
	{
		t_x = ((int)256 * (x - (-s->s_width / 2 + s->s_spr_x))
		* i->s_w / s->s_width) / 256;
		y = s->s_dsy - 1;
		if (s->t_y > 0 && x > 0 && x < i->w && s->t_y < s->z_buf[x])
			while (++y < s->s_dey)
			{
				d = (y) * 256 - i->h * 128 + s->s_h * 128;
				t_y = ((d * i->s_h) / s->s_h) / 256;
				if ((s->int_spr[i->s_h * t_y + t_x] & 0x00FFFFFF) != 0)
					i->int_img[y * i->w + x] = s->int_spr[i->s_h * t_y + t_x];
			}
	}
}

void	ft_fill_sprites_map(t_mlx_info *i, char **str)
{
	int		j;
	int		k;
	int		nb;
	int		*pos;

	nb = 0;
	k = -1;
	j = -1;
	while (str[++k])
	{
		j = -1;
		while (str[k][++j])
			if (str[k][j] == '2')
			{
				pos = malloc(sizeof(int) * 3);
				pos[0] = k;
				pos[1] = j;
				i->sprite->sprites[nb++] = pos;
			}
	}
	i->sprite->sprites[nb] = 0;
}

void	ft_checker_resolution(t_mlx_info *info)
{
	if (info->h % 320 != 0)
		while (info->h % 320 != 0)
			info->h++;
	if (info->w % 320 != 0)
		while (info->w % 320 != 0)
			info->w++;
	mlx_get_screen_size(info->mlx_ptr, &info->w, &info->h);
}

void	ft_sort_distance_sprites(t_sprite *s, t_all *r)
{
	int		j;
	int		k;
	int		*temp;

	j = -1;
	while (s->sprites[++j] != 0)
		s->sprites[j][2] = ((r->player_x - s->sprites[j][1]) * (r->player_x -
		s->sprites[j][1]) + (r->player_y - s->sprites[j][0]) * (r->player_y -
		s->sprites[j][0]));
	k = j;
	j = 0;
	while (j <= (k - 2))
	{
		if (s->sprites[j + 1][2] > s->sprites[j][2])
		{
			temp = s->sprites[j];
			s->sprites[j] = s->sprites[j + 1];
			s->sprites[j + 1] = temp;
		}
		j++;
	}
}
