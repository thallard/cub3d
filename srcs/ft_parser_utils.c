/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:48:36 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 19:33:49 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_map_contains(char *line, t_mlx_info *info)
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != '0' && line[i] != '2' && line[i] != '3' 
							&& line[i] != 'N' && line[i] != 'E' && line[i] != 'O' 
							&& line[i] != 'S' && line[i] != ' ')
		{
			info->error = -7;
			return (0);
		}
			
	return (1);
}

int		ft_fill_color(char *line, t_mlx_info *info)
{
	int		i;
	int		color;
	int		nb;

	nb = 0;
	color = 0;
	i = -1;
	if ((line[0] == 'F' && info->f_color[0] > 0))
	{
		info->error = -8;
		return (0);
	}
	while (line[++i])
	{
		if (line[i] == ' ')
			i++;
		else if (ft_isdigit(line[i]))
			nb = nb * 10 + line[i] - '0';
		else if (line[i] == ',')
		{
			if (line[0] == 'C')
				info->c_color[color++] = nb;
			else
				info->f_color[color++] = nb;
			nb = 0;
		}
	}
	return (1);
}