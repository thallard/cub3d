/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:16:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/18 15:39:06 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	ft_init_flags(t_mlx_info *info)
{
	info->mlx_ptr = NULL;
	info->mlx_win = NULL;
	info->img = NULL;
	info->width = 0;
	info->height = 0;
}

void	ft_init_flags_raycasting(t_all *ray, t_mlx_info *info, t_movements *mov)
{
	ray->posX = 2;
	ray->posY = 2;
	ray->dirX = 1;
	ray->dirY = 0;
	ray->planeX = 0;
	ray->planeY = 0.66;
	ray->cameraX = 0;
	ray->rayDirX = 0;
	ray->rayDirY = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->perpWallDist = 0;
	ray->drawEnd = 0;
	ray->drawStart = 0;
	ray->stepX = 0;
	ray->stepY = 0;
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
}

int		ft_print_errors(int error)
{
	if (error == -1)
		return (ft_printf("Erreur %d : Map error.\n", error));
	return (0);
}