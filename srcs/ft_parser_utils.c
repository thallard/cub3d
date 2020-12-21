/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:48:36 by thallard          #+#    #+#             */
/*   Updated: 2020/12/21 15:19:11 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/libft.h"
#include "../includes/cub3d.h"

int		ft_check_content_map(char *line, t_mlx_info *info,char *map[4096])
{
	static int		m = 0;
	int				paths;

	dprintf(1, "debug m en haut %d\n", m);
	if ((paths = ft_get_orientation(line)) == 3 && info->text[3] != NULL)
			m = 1;
	if (line[0] == 'C')
	{
		if (!(ft_fill_ceiling_color(line, info)))
			return (-1);
	}
	else if (line[0] == 'F')
	{	
		if (!(ft_fill_floor_color(line, info)))
			return (-1);
	}
	else if (line[0] == 'R' && line[0] != '\0')
	{
	if (!ft_fill_resolution(line, info))
		return (-1);
	} 
	else if (ft_isalpha(line[0]) && paths <= 3)
	{
		if (!ft_fill_path_texture(ft_strdup(line), info, paths))
			return (-1);
	}
	else if (m >= 1 && line && line[0] != '\0' && line[0] == '1')
	{dprintf(1, "debug m %d\n", m);
		if (!(ft_map_contains(line, info)))
			return (-1);
		dprintf(1, "debug m %d\n", m);
		map[m++ - 1] = ft_strdup(line);
	}
	free(line);
	return (m);
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
			info->error = -7;
			return (0);
		}
			
	return (1);
}

int		ft_fill_floor_color(char *line, t_mlx_info *info)
{
	int		i;
	int		color;
	int		nb;

	nb = 0;
	color = -1;
	i = 0;
	if (info->f_color[0] > 0 && info->f_color[1] > 0 && info->f_color[2] > 0)
		return ((info->error = -8) + 8);
	while (line[++i])
		if (line[i] == ' ')
			continue ;
		else if (ft_isprint(line[i]) && line[i] != ',' && !ft_isdigit(line[i]))
			return ((info->error = -8) + 8);
		else if (ft_isdigit(line[i]))
			nb = nb * 10 + line[i] - '0';
		else if (line[i] == ',')
		{
			if (++color > 3 || nb > 255)
				return ((info->error = -8) + 8);
			info->f_color[color] = nb;
			nb = 0;
		}
	return (1);
}

int		ft_fill_ceiling_color(char *line, t_mlx_info *info)
{
	int		i;
	int		color;
	int		nb;

	nb = 0;
	color = -1;
	i = 0;
	if (info->c_color[0] > 0 && info->c_color[1] > 0 && info->c_color[2] > 0)
		return ((info->error = -8) + 8);
	while (line[++i])
		if (line[i] == ' ')
			continue ;
		else if (ft_isprint(line[i]) && line[i] != ',' && !ft_isdigit(line[i]))
			return ((info->error = -8) + 8);
		else if (ft_isdigit(line[i]))
			nb = nb * 10 + line[i] - '0';
		else if (line[i] == ',')
		{
			if (++color > 3 || nb > 255)
				return ((info->error = -8) + 8);
			info->c_color[color] = nb;
			nb = 0;
		}
	return (1);
}