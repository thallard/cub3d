/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:21:36 by thallard          #+#    #+#             */
/*   Updated: 2020/12/21 19:02:23 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_exit_program(t_all *ray, t_mlx_info *info)
{
	(void)info;
	(void)ray;
	mlx_destroy_image(info->mlx_ptr, ray->infos->img);
	mlx_destroy_window(info->mlx_ptr, info->mlx_win);
	exit(0);
	return (1);
}

int		ft_print_errors(int error, t_mlx_info *i)
{
	if (i->error == -1)
		return (ft_printf("Error\n%d : Map error.\n", error));
	if (i->error == -5)
		return (ft_printf("Error\n%d : Wrong resolution in config file.\n", i->error));
	if (i->error == -6)
		return (ft_printf("Error\n%d : Wrong path for a texture.\n", i->error));
	if (i->error == -7)
		return (ft_printf("Error\n%d : Invalid format map.\n", i->error));
	if (i->error == -8)
		return (ft_printf("Error\n%d : Invalid color floor/ceiling.\n", i->error));
	if (i->error == -9)
		return (ft_printf("Error\n%d : Invalid path sprite.\n", i->error));
	return (0);
}

int		get_spawns(char **str)
{
	int		s;
	int		i;
	int		j;

	j = -1;
	s = 0;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
			if (ft_isalpha(str[j][i]))
				s = s + 1;
	}
	return (s);
}