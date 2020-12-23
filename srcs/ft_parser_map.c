/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by thallard          #+#    #+#             */
/*   Updated: 2020/12/23 17:50:34 by thallard         ###   ########lyon.fr   */
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
	if (!get_spawns(str) || !(ft_fill_map(i, str, l, -1)))
		return ((i->error = -7) + 7);
	return (1);
}

int		ft_check_walls_map(t_mlx_info *i, int rows, char **str)
{
	int		j;
	int		k;

	j = -1;
	while (str[++j] && (k = -1))
		while (str[j][++k])
			if (str[j][k] == '4')
			{
				if (k == (int)(ft_strlen(str[j]) - 1) || !k || j == rows || !j)
					return (0);
				else if (!(ft_check_map_zero(i, str, k, j)))
					return (0);
			}
	ft_free_str_map(str, rows);
	return (1);
}

int		ft_check_map_zero(t_mlx_info *i, char **s, int k, int j)
{
	(void)i;
	if (s[j][k] == '4' && s[j + 1] != NULL && k > (int)ft_strlen(s[j + 1]))
		return (0);
	if (s[j - 1][k - 1] == '5' || s[j - 1][k] == '5' || s[j - 1][k + 1] == '5')
		return (0);
	else if (s[j][k + 1] == '5' || s[j][k - 1] == '5')
		return (0);
	else if (s[j + 1][k - 1] == '5' || s[j + 1][k] == '5'
									|| s[j + 1][k + 1] == '5')
			return (0);
	return (1);
}

int		ft_fill_map(t_mlx_info *i, char **s, int rows, int k)
{
	int		j;

	ft_fill_sprites_map(i, s);
	while (s[++k] && (j = -1))
		while (s[k][++j])
			if (s[k][j] == ' ')
			{
				s[k][j] = '5';
				i->map[k][j] = 4;
			}
			else if (s[k][j] == '0' || s[k][j] == '2' || ft_isalpha(s[k][j]))
			{
				if (ft_isalpha(s[k][j]))
				{
						ft_set_player_spawn(i, k, j, s[k][j]);
						i->map[k][j] = 0;
				}
				else
					i->map[k][j] = s[k][j] - '0';
				s[k][j] = '4';
			}
			else if (ft_isdigit(s[k][j]))
				i->map[k][j] = s[k][j] - '0';
	i->map[k] = 0;
	if (!(ft_check_walls_map(i, rows, s)))
		return (0);
	return (1);
}

void	ft_set_player_spawn(t_mlx_info *info, int y, int x, char c)
{
	info->orientation = c;
	info->player_y = (double)y + 0.5;
	info->player_x = (double)x + 0.5;
}