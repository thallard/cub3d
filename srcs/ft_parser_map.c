/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by thallard          #+#    #+#             */
/*   Updated: 2020/12/20 16:16:50 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_parcours_map(t_mlx_info *info, char *line)
{
	int				i;
	static int		rows = 0;
	int				tmp;
	int				j;

	j = 0;
	i = -1;
	if (line[0] != '\0')
		rows++;
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
			info->map[rows][j++] = line[i];
	}
	return (1);
}

int		ft_malloc_map(t_mlx_info *i, char **str)
{
	int		l;
	int		j;
	int		size;

	l = 0;
	while (str[l++])
		;
	if (!(i->map = malloc(sizeof(int *) * (l + 1))))
		return (0);
	l = -1;
	while (str[++l])
	{
		j = 0;
		size = 1;
		while (str[l][++j])
			size++;
		if (!(i->map[l] = malloc(sizeof(int) * size)))
			return (0);
	}
	if (!(ft_fill_map(i, str, l)))
	{
		i->error = -7;
		return (0);
	}
	return (1);
}

int		ft_check_walls_map(t_mlx_info *i, int rows, char **str)
{
	int		j;
	int		k;

	j = -1;
	k = -1;
	while (str[++j])
	{
		k = -1;
		while (str[j][++k])
		{
			if (str[j][k] == '4')
			{
				if (k == (int)ft_strlen(str[j]) || !k || j == rows || j == 0)
					return (0);
				else if (!(ft_check_map_zero(i, str, k, j)))
					return (0);
			}
		}
	}
	return (1);
}

int		ft_check_map_zero(t_mlx_info *i, char **s, int k, int j)
{
	(void) i;
	if (s[j - 1][k - 1] == '5' || s[j - 1][k] == '5' || s[j - 1][k + 1] == '5')
		return (0);
	else if (s[j][k + 1] == '5' || s[j][k - 1] == '5')
		return (0);
	else if (s[j + 1][k - 1] == '5' || s[j + 1][k] == '5'
									|| s[j + 1][k + 1] == '5')
		return (0);
	return (1);
}

int		ft_fill_map(t_mlx_info *i, char **str, int rows)
{
	int		k;
	int		j;
	int		l;
	int		tmp;

	k = -1;
	while (str[++k])
	{
		j = -1;
		l = -1;
		tmp = l;
		while (str[k][++j])
		{
			if (str[k][j] == '0')
			{
				i->map[k][++l] = str[k][j] - '0';
				str[k][j] = '4';
			}
			else if (ft_isdigit(str[k][j]))
				i->map[k][++l] = str[k][j] - '0';
			else if (str[k][j] == ' ')
			{
				str[k][j] = '5';
				i->map[k][++l] = 4;
			}
		}
	}
	if (!(ft_check_walls_map(i, rows, str)))
		return (0);
	return (1);
}
