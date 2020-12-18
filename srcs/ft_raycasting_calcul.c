/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_calcul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:24:41 by thallard          #+#    #+#             */
/*   Updated: 2020/12/18 15:29:09 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

// void	ft_print_textures(t_all *ray, t_mlx_info *i, int x)
// {
// 	int texX = (int)(wallX * (double)texWidth);
// 	if(ray->side == 0 && ray->rayDirX > 0)
// 		texX = texWidth - texX - 1;
// 	if(ray->side == 1 && ray->rayDirY < 0)
// 		texX = texWidth - texX - 1;
// 	double step = 1.0 * texHeight / ray->lineHeight;
// 	double texPos = (ray->drawStart - info->height / 2 + ray->lineHeight / 2) * step;
// 	int i = -1;
// 	while (++i  < ray->drawStart)
// 	 	char_image[i * info->width + x] = 200 + 16 * 16 * 216 + 16 * 16 * 16 * 173;
// 	while (ray->drawStart  < ray->drawEnd)
// 	{	
// 		if (ray->side == 1)
// 		{
// 			int textureY = (int)texPos & (texHeight - 1);
// 			texPos += step;
// 			long color = info->texture[0][texHeight * textureY + texX];
// 			char_image[ray->drawStart * info->width + x] = color;
// 		}
// 		ray->drawStart = ray->drawStart + 1;
// 	}
// 	while (ray->drawEnd < info->height)
// 		char_image[ray->drawEnd++ * info->width + x] = 144 + 16 * 16 * 238 + 16 * 16 * 16 * 144;
// }