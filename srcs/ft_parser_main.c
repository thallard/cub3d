/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:37:12 by thallard          #+#    #+#             */
/*   Updated: 2020/12/19 09:57:02 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_check_map(char *map_name, t_mlx_info *info)
{
	int		fd;
	char	*line;
	int		i;
	int		paths;
	int map;

	if ((fd = open(map_name, O_RDONLY)) < 0)
		return (0);
	paths = 0;
	i = 0;
	map = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (map)
		{
			ft_parcours_map(info, line);
		}
			
		if ((paths = ft_get_orientation(line)) == 3)
			map = 1;
		if (line[0] == 'R' && line[0] != '\0')
		{
			if (!ft_fill_resolution(line, info))
				return (0);
		}
		else if (ft_isalpha(line[0]))
			ft_fill_path_texture(ft_strdup(line), info, paths);
	//	dprintf(1, "oui\n");
		free(line);
	}
	ft_parcours_map(info, line);
	if (line)
		free(line);
	return (1);
}

int		ft_fill_path_texture(char *line, t_mlx_info *info, int nb_paths)
{
	char	str[50];
	int		i;
	int		tmp;
	void	*xpm_image;

	i = 2;
	tmp = -1;
	while (line[++i] == ' ' || line[i] == '\t')
		;
	while (line[i])
		str[++tmp] = line[i++];
	str[++tmp] = '\0';
	//dprintf(1, "%s\n", str);
	xpm_image = mlx_xpm_file_to_image(info->mlx_ptr, str, &info->t_w, &info->t_h);
	info->texture[nb_paths] = (int *)mlx_get_data_addr(xpm_image, &i, &i, &i);
	free(line);
	return (1);
}

int		ft_fill_resolution(char *line, t_mlx_info *info)
{
	int		i;
	int		space;

	space = 0;
	i = 1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) && !space)
			info->width = info->width * 10 + line[i] - '0';
		if (line[i] == ' ' || line[i] == '\t')
			space = 1;
		if (space && ft_isdigit(line[i]))
			info->height = info->height * 10 + line[i] - '0';
	}
	if (info->height <= 0 || info->width <= 0)
		return (0);
	info->mlx_win = mlx_new_window(info->mlx_ptr, info->width, info->height, "Cub3D");
	return (1);
}

int		ft_get_orientation(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (2);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (3);
	return (-1);
}