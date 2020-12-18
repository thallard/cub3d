/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:12:25 by thallard          #+#    #+#             */
/*   Updated: 2020/12/18 13:45:54 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	return (keycode);
}
