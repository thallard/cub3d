/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:37:12 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 16:20:59 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../minilibx/mlx.h"

int		ft_check_map(char *map_name, t_mlx_info *info, int m, int paths)
{
	int		fd;
	char	*line;
	char	*map[4096];

	if (check_ext(map_name) || (fd = open(map_name, O_RDONLY)) < 0)
		return ((info->error = -1) + 1);
	while (get_next_line(fd, &line) == 1)
	{
		if ((paths = ft_get_orientation(line)) == 3)
			m = 1;
		if (!(ft_check_content_map(line, info, paths)))
			return (0);
		if (m >= 1 && line[0] != '\0' && paths == -1 && !ft_isalpha(line[0]))
		{
			if (!(ft_map_contains(line, info)))
				return (0);
			map[m++ - 1] = ft_strdup(line);
		}
		free(line);
	}
	if (!(check_map(line, info, map, m)))
		return (0);
	return (1);
}

int		ft_fill_path_texture(char *line, t_mlx_info *i, int nb_paths)
{
	char	str[400];
	int		j;
	int		tmp;
	void	*xpm_image;

	j = 2;
	tmp = -1;
	while (line[++j] == ' ')
		;
	while (line[j])
		str[++tmp] = line[j++];
	str[++tmp] = '\0';
	i->img = mlx_new_image(i->mlx_ptr, i->w, i->h);
	i->int_img = (int *)mlx_get_data_addr(i->img, &j, &j, &j);
	xpm_image = mlx_xpm_file_to_image(i->mlx_ptr, str, &i->t_w, &i->t_h);
	if (!xpm_image || i->text[nb_paths] != 0)
		return ((i->error = -6) + 6);
	i->text[nb_paths] = (int *)mlx_get_data_addr(xpm_image, &j, &j, &j);
	free(line);
	return (1);
}

int		ft_fill_resolution(char *line, t_mlx_info *info)
{
	int i;
	int space;

	space = 0;
	i = 0;
	if (info->h >= 1 || info->w >= 1)
		return ((info->error = -5) + 5);
	while (line[++i] == ' ')
		;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && !space)
			info->w = info->w * 10 + line[i] - '0';
		if (line[i] == ' ')
			space = 1;
		if (space && ft_isdigit(line[i]))
			info->h = info->h * 10 + line[i] - '0';
		i++;
	}
	if (info->h <= 0 || info->w <= 0)
		return ((info->error = -5) + 5);
	ft_checker_resolution(info);
	dprintf(1, "debug : %d %d\n", info->w, info->h);
	info->mlx_win = mlx_new_window(info->mlx_ptr, info->w, info->h, "cub3D");
	return (1);
}

int		ft_fill_sprite(char *line, t_mlx_info *i)
{
	int		l;
	char	tmp[400];
	int		j;
	void	*sprite;

	j = -1;
	l = 1;
	while (line[++l] == ' ')
		;
	while (line[l])
		tmp[++j] = line[l++];
	tmp[++j] = '\0';
	dprintf(1, "debug sprite %s\n", tmp);
	sprite = mlx_xpm_file_to_image(i->mlx_ptr, tmp, &i->s_w, &i->s_h);
	if (!sprite || i->sprite->s_path == 1)
		return ((i->error = -9) + 9);
	i->sprite->int_spr = (int *)mlx_get_data_addr(sprite, &j, &j, &j);
	i->sprite->s_path = 1;
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
