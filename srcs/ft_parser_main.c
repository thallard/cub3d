/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:37:12 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 14:47:47 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_check_map(char *map_name, t_mlx_info *info)
{
	int		fd;
	char	*line;
	char	*map[256];
	int		paths;
	int		m;

	if ((fd = open(map_name, O_RDONLY)) < 0)
		return (0);
	paths = 0;
	m = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if ((paths = ft_get_orientation(line)) == 3)
			m = 1;
		if (line[0] == 'R' && line[0] != '\0')
		{
			if (!ft_fill_resolution(line, info))
				return (0);
		}
		else if (ft_isalpha(line[0]))
			ft_fill_path_texture(ft_strdup(line), info, paths);
		else if (m >= 1 && line[0] != '\0')
			map[m++ - 1] = ft_strdup(line);
		free(line);
	}
	map[m++ - 1] = ft_strdup(line);
	map[m - 1] = 0;
	if (!(ft_malloc_map(info, map)))
		return (0);
	// ft_parcours_map(info, line);
	if (line)
		free(line);
	return (1);
}

int		ft_fill_path_texture(char *line, t_mlx_info *i, int nb_paths)
{
	char	str[50];
	int		j;
	int		tmp;
	void	*xpm_image;

	j = 1;
	tmp = -1;
	while (line[++j] == ' ')
		;
	while (line[j])
		str[++tmp] = line[j++];
	str[++tmp] = '\0';
	dprintf(1, "%s\n", str);
	i->img = mlx_new_image(i->mlx_ptr, i->w, i->h);
	i->int_img = (int *)mlx_get_data_addr(i->img, &j, &j, &j);
	xpm_image = mlx_xpm_file_to_image(i->mlx_ptr, str, &i->t_w, &i->t_h);
	i->text[nb_paths] = (int *)mlx_get_data_addr(xpm_image, &j, &j, &j);
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
			info->w = info->w * 10 + line[i] - '0';
		if (line[i] == ' ' || line[i] == '\t')
			space = 1;
		if (space && ft_isdigit(line[i]))
			info->h = info->h * 10 + line[i] - '0';
	}
	if (info->h <= 0 || info->w <= 0)
		return (0);
	info->mlx_win = mlx_new_window(info->mlx_ptr, info->w, info->h, "Cub3D");
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