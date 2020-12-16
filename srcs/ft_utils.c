/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:16:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/16 17:47:49 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_flags(t_mlx_info *info)
{
	info->mlx_ptr = NULL;
	info->mlx_win = NULL;
	info->width = 0;
	info->height = 0;
}

void	ft_init_flags_raycasting(t_raycasting *ray, t_mlx_info *info)
{
	ray->posX = 2;
	ray->posY = 2;
	ray->dirX = 1;
	ray->dirY = 0;
	ray->planeX = 0;
	ray->planeY = 0.90;
	ray->time = 0;
	ray->oldTime = 0; 
	ray->cameraX = 0;
	ray->rayDirX = 0;
	ray->rayDirY = 1;
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
}