/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:29:47 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 17:10:53 by thallard         ###   ########lyon.fr   */
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
