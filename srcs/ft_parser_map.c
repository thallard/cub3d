/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by thallard          #+#    #+#             */
/*   Updated: 2020/12/19 09:59:01 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_parcours_map(t_mlx_info *info, char *line)
{
	int		i;

	static int		rows = 0;

	i = -1;
	if (line[0] != '\0')
		rows++;
	int	tmp;
	int	j = 0;
	if (rows == 0)
		info->map = malloc(sizeof(int *) * 9);

	info->map[rows] = malloc(sizeof(int) * 25);
	while (line[++i] != '\0')
	{
		tmp = j;
		if (line[i] == '\t')
			while (j < tmp + 4)
				info->map[rows][j++] = -1;
		else if (ft_isdigit(line[i]))
			info->map[rows][j++] = line[i] - '0';
		else
		{
				info->map[rows][j++] = line[i];
		}
		
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
		
	}
	// int	im = -1;
	// if (line[0] != '\0')
	// {
	// 	while (++im < 10)
	// 	{
	// 		//dprintf(1, "[%d] ", info->map[rows][im]);
	// 	}
	// 	//	printf("\n");
	// }
	return (1);
}