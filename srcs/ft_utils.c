/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:21:36 by thallard          #+#    #+#             */
/*   Updated: 2020/12/22 17:58:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_exit_program(t_all *ray)
{
	mlx_destroy_image(ray->infos->mlx_ptr, ray->infos->img);
	mlx_destroy_window(ray->infos->mlx_ptr, ray->infos->mlx_win);
	exit(0);
	return (1);
}

int		ft_print_errors(int error, t_mlx_info *i)
{
	if (i->error == -1)
		return (ft_printf("Error\n%d : Wrong file/name file.\n", error));
	if (i->error == -3)
		return (ft_printf("Error\n%d : Wrong player position.\n", error));
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
	dprintf(1, "valeur de s = %d", s);
	// if (s == 0 || s >= 2)
	// 	return (0);
	return (1);
}

int		check_ext(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '.')
		;
	if (!ft_strncmp(str + i, ".cub", 5))
		return (0);
	return (1);
}