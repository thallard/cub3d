/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:04 by thallard          #+#    #+#             */
/*   Updated: 2020/12/19 09:53:07 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/libft.h"
#include "includes/cub3d.h"

#define texWidth 256
#define texHeight 256

int ft_move_forward(t_all *ray)
{
	// int worldMap[8][8]=
	// {
	// 	{1, 1, 1, 1, 1, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 2, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 1, 1, 1, 1}
	// };
	if (ray->mov->key_w)
	{
		if (ray->infos->map[(int)(ray->posX + ray->dirX * 0.13)][(int)ray->posY] == 0)
			ray->posX += ray->dirX * 0.13;
		if (ray->infos->map[(int)ray->posX][(int)(ray->posY + ray->dirY * 0.13)] == 0)	
			ray->posY += ray->dirY * 0.13;
	}
	if (ray->mov->key_a)
	{
		double oldDirX = ray->dirX;
		ray->dirX = ray->dirX * cos(-3.14 / 60) - ray->dirY * sin(-3.14 / 60);
		ray->dirY = oldDirX * sin(-3.14 / 60) + ray->dirY * cos(-3.14 / 60);
		double oldPlaneX = ray->planeX;
		ray->planeX = ray->planeX * cos(-3.14 / 60) - ray->planeY * sin(-3.14 / 60);
		ray->planeY = oldPlaneX * sin(-3.14 / 60) + ray->planeY * cos(-3.14 / 60);
	
	}
	if (ray->mov->key_s)
	{
		if (ray->infos->map[(int)(ray->posX - ray->dirX * 0.13)][(int)ray->posY] == 0)
			ray->posX -= ray->dirX * 0.13;
		if (ray->infos->map[(int)ray->posX][(int)(ray->posY - ray->dirY * 0.13)] == 0)	
			ray->posY -= ray->dirY * 0.13;
	}
	if (ray->mov->key_d)
	{
		double oldDirX = ray->dirX;
		ray->dirX = ray->dirX * cos(3.14 / 60) - ray->dirY * sin(3.14 / 60);
		ray->dirY = oldDirX * sin(3.14 / 60) + ray->dirY * cos(3.14 / 60);
		double oldPlaneX = ray->planeX;
		ray->planeX = ray->planeX * cos(3.14 / 60) - ray->planeY * sin(3.14 / 60);
		ray->planeY = oldPlaneX * sin(3.14 / 60) + ray->planeY * cos(3.14 / 60);
	}
	return (1);
}

int		loop_game(t_all *ray)
{
	ft_move_forward(ray);
	ft_affiche_mes_couilles(ray, ray->infos);
	return (1);
}

int		ft_affiche_mes_couilles(t_all *ray, t_mlx_info *info)
{

	// int worldMap[8][8] =
	// {
	// 	{1, 1, 1, 2, 4, 1, 1, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 2, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 1, 1, 1, 1}
	// };
	int		x;
	x = -1;
	int	width;
	int	height;
	int endian;
	int	bits_per_pixels;

	void *wood_texture;
	wood_texture = mlx_xpm_file_to_image(info->mlx_ptr, "./textures/SO_stone.xpm", &width, &height);
	int *buffer_texture;
	int oui;
	buffer_texture = (int *)mlx_get_data_addr(wood_texture, &bits_per_pixels, &oui, &endian);
	info->img = mlx_new_image(info->mlx_ptr, info->width, info->height);
	int *char_image = (int *)mlx_get_data_addr(info->img, &bits_per_pixels, &oui, &endian);
	
	while (++x < info->width)
	{
		ray->hit = 0;
			//calculate ray position and direction
		ray->cameraX = 2 * x / (double)info->width - 1; //x-coordinate in camera space
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;

		//which box of the map we're in
		ray->mapX = (int)ray->posX;
		ray->mapY = (int)ray->posY;

		//length of ray from one x or y-side to next x or y-side
		// ray->deltaDistX = fabs(1 / ray->rayDirX);
		// ray->deltaDistY = fabs(1 / ray->rayDirY);
		ray->deltaDistX = (ray->rayDirY == 0) ? 0 : (ray->rayDirX == 0) ? 1 : fabs(1 / ray->rayDirX);
		ray->deltaDistY = (ray->rayDirX == 0) ? 0 : (ray->rayDirY == 0) ? 1 : fabs(1 / ray->rayDirY);
		//calculate step and initial sideDist
		int		orientation;
		if (ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
		}
		if (ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
		}
		while (ray->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
				orientation = ray->rayDirX > 0 ? 1 : 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
				orientation = ray->rayDirY > 0 ? 2 : 3;
			}
			//Check if ray has hit a wall
			//dprintf(1, "Debug mapX = %d et mapY = %d\n", ray->mapX, ray->mapY);
			if (info->map[ray->mapX][ray->mapY] > 0) 
				ray->hit = 1;
		}
		//dprintf(1, "Position du player en X %f et en Y %f\n", ray->posX, ray->posY);
		double wallX = 0; 
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (ray->side == 0)
			ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;


  if (ray->side == 0)
  	wallX = ray->posY + ray->perpWallDist * ray->rayDirY;
	  else 
	  wallX = ray->posX + ray->perpWallDist * ray->rayDirX;
	   
	  wallX -= floor((wallX));

	   //Calculate height of line to draw on screen
	  ray->lineHeight = (int)(info->height / ray->perpWallDist);

		// if (x < 10)
	  	// dprintf(1, "debug lineHeight = %d et texX = %d et wallX = %f\n",ray->lineHeight, info->height, ray->perpWallDist);
	  int texX = (int)(wallX * (double)texWidth);
	// dprintf(1, "wallX = %f et texX %d\n ", wallX, texX);
	  if(ray->side == 0 && ray->rayDirX > 0)
	  	texX = texWidth - texX - 1;
	  if(ray->side == 1 && ray->rayDirY < 0)
	  	texX = texWidth - texX - 1;
	// if (x < 10)
	  //	dprintf(1, "debug texX = %d \n",texX);

		// if (ray->lineHeight < 0)
		// 	oui = 0;
		//calculate lowest and highest pixel to fill in current stripe
	ray->drawStart = ray->lineHeight * -1 / 2 + info->height / 2;
 	ray->drawEnd = ray->lineHeight / 2 + info->height / 2;

	if (ray->drawStart < 0)
		ray->drawStart = 0;
	if (ray->drawEnd >= info->height)
		ray->drawEnd = info->height - 1;
		//if (x < 10)
		//dprintf(1, "drawstart = %d et drawend = %d et color %d\n", ray->drawStart, ray->drawEnd, worldMap[ray->mapX][ray->mapY]);
	double step = 1.0 * texHeight / ray->lineHeight;
	double texPos = (ray->drawStart - info->height / 2 + ray->lineHeight / 2) * step;
	int i = -1;
	while (++i  < ray->drawStart)
	 	char_image[i * info->width + x] = 200 + 16 * 16 * 216 + 16 * 16 * 16 * 173;
	while (ray->drawStart  < ray->drawEnd)
	{	

			int textureY = (int)texPos & (texHeight - 1);
			texPos += step;
			long color = info->texture[orientation][texHeight * textureY + texX];
			char_image[ray->drawStart * info->width + x] = color;
		ray->drawStart = ray->drawStart + 1;
	}
	// while (ray->drawEnd < info->height)
	// 	char_image[ray->drawEnd++ * info->width + x] = 144 + 16 * 16 * 238 + 16 * 16 * 16 * 144;

	
	// int color = 000255000000;
	// 
	
	// int i = -1;
	// //dprintf(1, "drawstart avant crash %d et %d\n", ray->drawStart, ray->drawEnd);
	// 	while (++i < ray->drawStart)
	// 		mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, i, 000123000255);
		
	// while (ray->drawStart < ray->drawEnd)
	// {
	// 	ray->side = worldMap[ray->mapX][ray->mapY];
	// 	if (ray->side == 1)
	// 	{
	// 		mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawStart, 000255000000);
	// 	}
		
	// 	else if (ray->side == 2)
	// 		mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawStart, 000000255000);
	// 	 	ray->drawStart++;
	// }
	// while (ray->drawEnd < info->height)
	// 	mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawEnd++, 000123255020);
	
	ray->drawStart = 0;
	ray->drawEnd = 0;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->img, 0, 0);
	// FPS
	//ray->posY++;
	//dprintf(1, "PosY = %f et PosX = %f\n", ray->posY, ray->posX);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx_info	i;
	t_all		ray;
	t_movements	mov;

	ft_init_flags_movements(&mov);
	ft_init_flags(&i);
	i.mlx_ptr = mlx_init();
	if (argc != 2 || !ft_check_map(argv[1], &i))
		return (ft_print_errors(-1));
	ft_init_flags_raycasting(&ray, &i, &mov);
	ft_affiche_mes_couilles(&ray, &i);
	mlx_hook(i.mlx_win, 02, 1L<<0, key_press, &ray);
	mlx_hook(i.mlx_win, 03, 1L<<1, key_release, &ray);
	mlx_loop_hook(i.mlx_ptr, loop_game, &ray);
	
	mlx_loop(i.mlx_ptr);
	return (0);
}