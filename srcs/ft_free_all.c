/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:29:47 by thallard          #+#    #+#             */
/*   Updated: 2020/12/23 17:34:32 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	ft_free_str_map(char **str, int rows)
{
	while (rows >= 0)
		free(str[rows--]);
}