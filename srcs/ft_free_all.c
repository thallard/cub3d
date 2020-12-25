/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:29:47 by thallard          #+#    #+#             */
/*   Updated: 2020/12/25 12:25:59 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../minilibx/mlx.h"

void	ft_free_str_map(char **str, int rows)
{
	while (rows >= 0)
		free(str[rows--]);
}

int		ft_check_character_map(char *line, t_mlx_info *i)
{
	if (ft_strncmp(line, "R ", 2) && line[0] != '\0' &&
		ft_strncmp(line, "S ", 2) && ft_strncmp(line, "NO ", 3) &&
		ft_strncmp(line, "SO ", 3) && ft_strncmp(line, "WE ", 3) &&
		ft_strncmp(line, "EA ", 3) && ft_strncmp(line, "S ", 2)
		&& line[0] == '1' && line[0] == '0' && line[0] == ' ' &&
		line[0] == '2' && ft_strncmp(line, "F ", 2) &&
		ft_strncmp(line, "C ", 2))
	{
		i->error = -10;
		return (0);
	}
	return (1);
}

int		ft_check_empty(char *line, t_mlx_info *i)
{
	if (i->w == 0 || i->h == 0 || i->sprite->int_spr == NULL ||
		i->text[0] == NULL || i->text[1] == NULL ||
		i->text[2] == NULL || i->text[3] == NULL ||
		(i->c_color[0] == -1 || i->c_color[1] == -1 || i->c_color[2] == -1)
		|| (i->f_color[0] == -1 || i->f_color[1] == -1 || i->f_color[2] == -1))
		return ((i->error = -11) + 11);
	return (1);
}
