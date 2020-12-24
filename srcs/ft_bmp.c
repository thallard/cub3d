/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:05:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 15:11:49 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../includes/mlx.h"

void	ft_bzero(void *pointer, int size)
{
	int		i;

	i = -1;
	if (size == 0)
		return ;
	while (++i < size)
		((char *)pointer)[i] = '\0';
}

void	ft_init_bmp(t_all *a, t_mlx_info *i)
{
	if (!(a->bmp = malloc(sizeof(t_bmp))))
		ft_exit_program(a);
	ft_bzero(a->bmp->header, 54);
	a->bmp->w = i->w;
	a->bmp->height = i->h;
	a->bmp->bytes_number = 32;
	a->bmp->width_bytes = ((a->bmp->w * a->bmp->bytes_number + 31) / 32) * 4;
	a->bmp->image_s = a->bmp->width_bytes * a->bmp->height;
	a->bmp->bytes_s = 40;
	a->bmp->header_s = 54;
	a->bmp->file_s = 54 + a->bmp->image_s;
	a->bmp->biplanes = 1;
	ft_fill_bmp_header(a);
}

void	ft_fill_bmp_header(t_all *a)
{
	ft_memcpy(a->bmp->header, "BM", 2);
	ft_memcpy(a->bmp->header + 2, &a->bmp->file_s, 4);
	ft_memcpy(a->bmp->header + 10, &a->bmp->header_s, 4);
	ft_memcpy(a->bmp->header + 14, &a->bmp->bytes_s, 4);
	ft_memcpy(a->bmp->header + 18, &a->bmp->w, 4);
	ft_memcpy(a->bmp->header + 22, &a->bmp->height, 4);
	ft_memcpy(a->bmp->header + 26, &a->bmp->biplanes, 4);
	ft_memcpy(a->bmp->header + 28, &a->bmp->bytes_number, 4);
	ft_memcpy(a->bmp->header + 34, &a->bmp->image_s, 4);
	a->bmp->fd = open("./screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	ft_write_screenshot_in_bmp(a);
}

void	ft_write_screenshot_in_bmp(t_all *a)
{
	int		height_to_write;

	height_to_write = a->bmp->height;
	write(a->bmp->fd, a->bmp->header, 54);
	while (height_to_write)
	{
		write(a->bmp->fd, a->infos->int_img
		+ (height_to_write * a->bmp->w), a->bmp->w * 4);
		height_to_write--;
	}
	close(a->bmp->fd);
}
