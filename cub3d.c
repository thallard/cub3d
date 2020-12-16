/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:04 by thallard          #+#    #+#             */
/*   Updated: 2020/12/16 18:06:51 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/libft.h"
#include "includes/cub3d.h"

int		ft_fill_resolution(char *line, t_mlx_info *info)
{
	int		i;
	char	*str;
	int		space;

	space = 0;
	i = 1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) && !space)
			info->width = info->width * 10 + line[i] - '0';
		if (line[i] == ' ')
			space = 1;
		if (space && ft_isdigit(line[i]))
			info->height = info->height * 10 + line[i] - '0';
	}
	if (info->height <= 0 || info->width <= 0)
		return (0);
	return (1);
}

int		ft_check_map(char *map_name, t_mlx_info *info)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(map_name, O_RDONLY) ) < 0)
		return (0);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			if (!ft_fill_resolution(line, info))
				return (0);
	}
	return (1);
}

int		ft_print_errors(int error)
{
	if (error == -1)
		return (ft_printf("Erreur %d : Map error.\n", error));
	return (0);
}

int ft_move_forward(int keycode, t_raycasting *ray)
{
int worldMap[8][8]=
{
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
  	{1, 1, 1, 1, 1, 1, 1, 1}
  
};
	if (keycode == 126)
	{
		if (worldMap[(int)(ray->posX + ray->dirX * 1)][(int)ray->posY] == 0)
		{
			ray->posX += ray->dirX * 1;
			//ft_printf("oui");
							ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
		}
		if (worldMap[(int)ray->posX][(int)(ray->posY + ray->dirY * 1)] == 0)	
		{
			ray->posY += ray->dirY * 1;

			//ft_printf("non");
							ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
		}
	}
	if (keycode == 123)
	{
		double oldDirX = ray->dirX;
		ray->dirX = ray->dirX * cos(-3.14 / 4) - ray->dirY * sin(-3.14 / 4);
		ray->dirY = oldDirX * sin(-3.14 / 4) + ray->dirY * cos(-3.14 / 4);
		double oldPlaneX = ray->planeX;
		ray->planeX = ray->planeX * cos(-3.14 / 4) - ray->planeY * sin(-3.14 / 4);
		ray->planeY = oldPlaneX * sin(-3.14 / 4) + ray->planeY * cos(-3.14 / 4);
		ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
	}
	if (keycode == 125)
	{
		if (worldMap[(int)(ray->posX - ray->dirX * 1)][(int)ray->posY] == 0)
		{
			ray->posX -= ray->dirX * 1;
			//ft_printf("oui");
			ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
		}
		if (worldMap[(int)ray->posX][(int)(ray->posY - ray->dirY * 1)] == 0)	
		{
			ray->posY -= ray->dirY * 1;
			//ft_printf("non");
			ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
		}
	}
	if (keycode == 124)
	{
		double oldDirX = ray->dirX;
		ray->dirX = ray->dirX * cos(3.14 / 4) - ray->dirY * sin(3.14 / 4);
		ray->dirY = oldDirX * sin(3.14 / 4) + ray->dirY * cos(3.14 / 4);
		double oldPlaneX = ray->planeX;
		ray->planeX = ray->planeX * cos(3.14 / 4) - ray->planeY * sin(3.14 / 4);
		ray->planeY = oldPlaneX * sin(3.14 / 4) + ray->planeY * cos(3.14 / 4);
		ft_affiche_mes_couilles(ray, ray->infos, ray->infos->mlx_ptr, ray->infos->mlx_win);
	}
		ft_printf("jai appuye sur la touche : %d\n", keycode);
	
		return (keycode);
}

int		ft_affiche_mes_couilles(t_raycasting *ray, t_mlx_info *info, void *mlx, void *window)
{

int worldMap[8][8]=
{
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};
	int		x;
	x = -1;
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
		ray->deltaDistX = fabs(1 / ray->rayDirX);
		ray->deltaDistY = fabs(1 / ray->rayDirY);
		// ray->deltaDistX = (ray->rayDirY == 0) ? 0 : (ray->rayDirX == 0) ? 1 : fabs(1 / ray->rayDirX);
		// ray->deltaDistY = (ray->rayDirX == 0) ? 0 : (ray->rayDirY == 0) ? 1 : fabs(1 / ray->rayDirY);
		//calculate step and initial sideDist
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
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[ray->mapX][ray->mapY] > 0) 
				ray->hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (ray->side == 0)
	  		ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
      else
	  		ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
	   //Calculate height of line to draw on screen
      ray->lineHeight = (info->height / ray->perpWallDist);
	 dprintf(1, "debug lineHeight = %d\n",ray->lineHeight);
	int oui = 0;
	int ouioui = 0;
	if (ray->lineHeight < 0)
		oui = 0;
      //calculate lowest and highest pixel to fill in current stripe
    	ray->drawStart = ray->lineHeight * -1 / 2 + info->height / 2;
 		ray->drawEnd = ray->lineHeight / 2 + info->height / 2;
		if (oui)
		{
			ouioui = ray->drawEnd;
			ray->drawEnd = ray->drawStart;
			ray->drawStart = ouioui;
		}
		if(ray->drawStart < 0)
			ray->drawStart = 0;
		if(ray->drawEnd >= info->height)
			ray->drawEnd = info->height - 1;
	//dprintf(1, "drawstart = %f et drawend = %f\n", drawStart, drawEnd);
	int color = 000255000000;
	// if (x < 10)
	// dprintf(1, "drawstart = %d et drawend = %d et color %d\n", drawStart, drawEnd, worldMap[mapX][mapY]);
	int i = -1;
	dprintf(1, "drawstart avant crash %d et %d\n", ray->drawStart, ray->drawEnd);
		while (++i < ray->drawStart)
			mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, i, 000123000255);
		
	while (ray->drawStart < ray->drawEnd)
	{
		ray->side = worldMap[ray->mapX][ray->mapY];
		if (ray->side == 1)
			mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawStart, 000255000000);
		else if (ray->side == 2)
			mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawStart, 000000255000);
			ray->drawStart++;
	}
	while (ray->drawEnd < info->height)
		mlx_pixel_put(ray->infos->mlx_ptr, ray->infos->mlx_win, x, ray->drawEnd++, 000123255020);

	ray->drawStart = 0;
	ray->drawEnd = 0;
	}
	// FPS
	//ray->posY++;
	//dprintf(1, "PosY = %f et PosX = %f\n", ray->posY, ray->posX);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx_info i;
	t_raycasting ray;

	ft_init_flags(&i);
	i.mlx_ptr = mlx_init();
	i.width = 1920;
	i.height = 1080;
	i.mlx_win = mlx_new_window(i.mlx_ptr, i.width, i.height, "Cub3D");

	ft_init_flags_raycasting(&ray, &i);
	ft_affiche_mes_couilles(&ray, &i, i.mlx_ptr, i.mlx_win);
	mlx_key_hook(i.mlx_win, ft_move_forward, &ray);
	//char touche = getch();
	//ft_printf("Jai appuyer sur la touche : %d", touche);
	
	mlx_loop(i.mlx_ptr);
	return (0);
}