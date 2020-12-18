/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by thallard          #+#    #+#             */
/*   Updated: 2020/12/18 18:48:39 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_parcours_map(t_mlx_info *info, int fd)
{
	int		i;
	char	*line = NULL;
	int		rows;
	int		spaces;
	int		num;
	info->map[0][0] = 0;
	num = 0;
	rows = 0;
	spaces = 0;
	i = -1;
	while (get_next_line(fd, &line) == 1)
	{
		dprintf(1, "%s ", line);
		i = 2;
		// while (line[i])
		// {
		// 	// if (line[i] == '0' || line[i] == '1')
		// 	// {
		// 	// 	num = 1;
		// 	// 	info->map[0][i] = line[i];
		// 	// }
		// 	// else if ((line[i] == ' ' || line[i] == '\t') && num && !spaces)
		// 	// {
		// 	// 	spaces = 1;
		// 	// 	line = ft_strtrim(line, "\t");
		// 	// 	i = -1;
		// 	// }
		// 	i++;
		// 		dprintf(1, "[%c] ", line[i]);
		// }
		//free(line);
		rows++;
	}
	// i = -1;
	// while (++i < 30)
	// {
	// 	dprintf(1, "[%d] ", info->map[0][i]);
	// }
	printf("\n");
	return (1);
}