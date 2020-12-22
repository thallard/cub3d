/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:48:36 by thallard          #+#    #+#             */
/*   Updated: 2020/12/21 19:09:23 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_check_content_map(char *line, t_mlx_info *info, int paths)
{
	if (line[0] == 'F')
		if (!(ft_fill_floor_color(line, info, -1, 0)))
			return (0);
	if (line[0] == 'C')
		if (!(ft_fill_ceiling_color(line, info, -1, 0)))
			return (0);
	if (line[0] == 'S')
		if (!(ft_fill_sprite(line, info)))
			return (0);
	if (line[0] == 'R' && line[0] != '\0')
		if (!ft_fill_resolution(line, info))
			return (0);
	if (line[0] != 'R' && ft_isalpha(line[0]) && paths != -1)
		if (!ft_fill_path_texture(ft_strdup(line), info, paths))
			return (0);
	return (1);
}

int		check_map(char *line, t_mlx_info *info, char **map, int map_row)
{	
	if (!(ft_map_contains(line, info)))
		return (0);
	map[map_row++ - 1] = ft_strdup(line);
	map[map_row - 1] = 0;
	if (!(ft_malloc_map(info, map)))
		return (0);
	if (line)
		free(line);
	return (1);
}

int		ft_map_contains(char *line, t_mlx_info *info)
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != '0' && line[i] != '2' && line[i] != '3'
						&& line[i] != 'N' && line[i] != 'E' && line[i] != 'O'
						&& line[i] != 'S' && line[i] != ' ')
						{
							dprintf(1, "%c\n", line[i]);
						return ((info->error = -7) + 7);
						}
		
	return (1);
}

int		ft_fill_floor_color(char *line, t_mlx_info *i, int color, int nb)
{
	int		j;

	j = 0;
	if (i->f_color[0] > 0 && i->f_color[1] > 0 && i->f_color[2] > 0)
		return ((i->error = -8) + 8);
	while (line[++j])
	{
		if (line[j] == ' ' && (color >= 0 || nb != 0))
			return ((i->error = -8) + 8);
		if (line[j] == ' ')
			continue ;
		if (ft_isprint(line[j]) && line[j] != ',' && !ft_isdigit(line[j]))
			return ((i->error = -8) + 8);
		if (ft_isdigit(line[j]))
			nb = nb * 10 + line[j] - '0';
		if (line[j] == ',' || line[j + 1] == '\0')
		{
			if (++color > 3 || nb > 255)
				return ((i->error = -8) + 8);
			i->f_color[color] = nb;
			nb = 0;
		}
	}
	return (1);
}

int		ft_fill_ceiling_color(char *line, t_mlx_info *i, int color, int nb)
{
	int		j;

	j = 0;
	if (i->c_color[0] > 0 && i->c_color[1] > 0 && i->c_color[2] > 0)
		return ((i->error = -8) + 8);
	while (line[++j])
	{
		if (line[j] == ' ' && (color >= 0 || nb != 0))
			return ((i->error = -8) + 8);
		if (line[j] == ' ')
			continue ;
		if (ft_isprint(line[j]) && line[j] != ',' && !ft_isdigit(line[j]))
			return ((i->error = -8) + 8);
		if (ft_isdigit(line[j]))
			nb = nb * 10 + line[j] - '0';
		if (line[j] == ',' || line[j + 1] == '\0')
		{
			if (++color > 3 || nb > 255)
				return ((i->error = -8) + 8);
			i->c_color[color] = nb;
			nb = 0;
		}
	}
	return (1);
}
