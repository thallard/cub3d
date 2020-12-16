/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:41:55 by thallard          #+#    #+#             */
/*   Updated: 2020/12/16 17:31:46 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D
# define FT_CUB3D

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_mlx_info
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
}				t_mlx_info;

typedef struct	s_raycasting
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time; 
	double		oldTime; 
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			drawEnd;
	int			drawStart;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	t_mlx_info	*infos;
}				t_raycasting;

int		ft_fill_resolution(char *line, t_mlx_info *info);
int		ft_affiche_mes_couilles(t_raycasting *ray, t_mlx_info *info, void *mlx, void *window);

void	ft_init_flags(t_mlx_info *info);
void	ft_init_flags_raycasting(t_raycasting *ray, t_mlx_info *info);

int ft_move_forward(int keycode, t_raycasting *ray);


#endif