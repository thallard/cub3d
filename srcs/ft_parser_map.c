/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by thallard          #+#    #+#             */
/*   Updated: 2020/12/21 18:21:34 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

int		ft_malloc_map(t_mlx_info *i, char **str)
{
	int		l;
	int		j;
	int		size;

	l = 0;
	while (str[l++])
		;
	if (!(i->map = malloc(sizeof(int *) * (l + 10))))
		return (0);
	l = -1;
	while (str[++l])
	{
		j = -1;
		size = 1;
		while (str[l][++j])
			size++;
		if (!(i->map[l] = malloc(sizeof(int) * size + 10)))
			return (0);
	}
	if (get_spawns(str) >= 2 || !(ft_fill_map(i, str, l, -1)))
		return ((i->error = -7) + 7);
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
							dprintf(1, "%s %d %d\n", str[j], j, k);
				if (k == (int)ft_strlen(str[j]) || k == 0 || j == rows || j == 0)
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
		{

			return (0);
		}
		
	return (1);
}

int		ft_fill_map(t_mlx_info *i, char **str, int rows, int k)
{
	int		j;
	
	while (str[++k])
	{
		j = -1;
		while (str[k][++j])
			if (str[k][j] == ' ')
			{
				str[k][j] = '5';
				i->map[k][j] = 4;
			}
			else if (str[k][j] == '0' || str[k][j] == '2' || ft_isalpha(str[k][j]))
			{
				i->map[k][j] = str[k][j] - '0';
				str[k][j] = '4';
			}
			else if (ft_isdigit(str[k][j]))
				i->map[k][j] = str[k][j] - '0';
	}
	if (get_spawns(str) >= 2 || !(ft_check_walls_map(i, rows, str)))
		return (0);
	return (1);
}
