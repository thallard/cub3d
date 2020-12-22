/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:12:25 by thallard          #+#    #+#             */
/*   Updated: 2020/12/22 15:47:32 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_forward(t_all *r)
{
	if (r->mov->key_escape)
		ft_exit_program(r);
	if (r->mov->key_w)
	{
		if (r->infos->map[(int)(r->player_x + r->dir_x * 0.13)]
		[(int)r->player_y] == 0)
			r->player_x += r->dir_x * 0.13;
		if (r->infos->map[(int)r->player_x]
		[(int)(r->player_y + r->dir_y * 0.13)] == 0)
			r->player_y += r->dir_y * 0.13;
	}
	if (r->mov->key_s)
	{
		if (r->infos->map[(int)(r->player_x - r->dir_x * 0.13)]
		[(int)r->player_y] == 0)
			r->player_x -= r->dir_x * 0.13;
		if (r->infos->map[(int)r->player_x]
		[(int)(r->player_y - r->dir_y * 0.13)] == 0)
			r->player_y -= r->dir_y * 0.13;
	}
}

void	ft_rotate_player(t_all *r)
{
	double		s_x;
	
	if (r->mov->key_al)
	{
		s_x = r->dir_x;
		r->dir_x = r->dir_x * cos(-ROTATE) - r->dir_y * sin(-ROTATE);
					r->dir_y = s_x * sin(-ROTATE) + r->dir_y * cos(-ROTATE);
		s_x = r->plane_x;
		r->plane_x = r->plane_x * cos(-ROTATE) -
					r->plane_y * sin(-ROTATE);
		r->plane_y = s_x * sin(-ROTATE) + r->plane_y * cos(-ROTATE);
	}
	if (r->mov->key_ar)
	{
		s_x = r->dir_x;
		r->dir_x = r->dir_x * cos(ROTATE) - r->dir_y * sin(ROTATE);
					r->dir_y = s_x * sin(ROTATE) + r->dir_y * cos(ROTATE);
		s_x = r->plane_x;
		r->plane_x = r->plane_x * cos(ROTATE) - 
					r->plane_y * sin(ROTATE);
		r->plane_y = s_x * sin(ROTATE) + r->plane_y * cos(ROTATE);
	}
}

void	ft_move_right_and_left(t_all *r)
{
	if (r->mov->key_a)
	{
		r->player_y -= r->dir_x * SPEED;
		r->player_x += r->dir_y * SPEED;
		if (r->infos->map[(int)r->player_x][(int)r->player_y] != 0)
		{
			r->player_y += r->dir_x * SPEED;
			r->player_x -= r->dir_y * SPEED;
		}
	}
	if (r->mov->key_d)
	{
		r->player_y += r->dir_x * SPEED;
		r->player_x -= r->dir_y * SPEED;
		if (r->infos->map[(int)r->player_x][(int)r->player_y] != 0)
		{
			r->player_y -= r->dir_x * SPEED;
			r->player_x += r->dir_y * SPEED;
		}
	}
	
}

int		key_press(int keycode, t_all *ray)
{
	if (keycode == 13)
		ray->mov->key_w = 1;
	else if (keycode == 0)
		ray->mov->key_a = 1;
	else if (keycode == 1)
		ray->mov->key_s = 1;
	else if (keycode == 2)
		ray->mov->key_d = 1;
	else if (keycode == 124)
		ray->mov->key_ar = 1;
	else if (keycode == 123)
		ray->mov->key_al = 1;
	else if (keycode == 53)
		ray->mov->key_escape = 1;
	return (keycode);
}

int		key_release(int keycode, t_all *ray)
{
	if (keycode == 13)
		ray->mov->key_w = 0;
	else if (keycode == 0)
		ray->mov->key_a = 0;
	else if (keycode == 1)
		ray->mov->key_s = 0;
	else if (keycode == 2)
		ray->mov->key_d = 0;
	else if (keycode == 124)
		ray->mov->key_ar = 0;
	else if (keycode == 123)
		ray->mov->key_al = 0;
	else if (keycode == 53)
		ray->mov->key_escape = 0;
	return (keycode);
}
