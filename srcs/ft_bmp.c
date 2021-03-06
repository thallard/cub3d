/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:05:21 by thallard          #+#    #+#             */
/*   Updated: 2020/12/24 16:52:58 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"
#include "../minilibx/mlx.h"

void	ft_bzero(void *pointer, int size)
{
	int		i;

	i = -1;
	if (size == 0)
		return ;
	while (++i < size)
		((char *)pointer)[i] = '\0';
}

void	ft_init_bmp(t_all *a, t_mlx_info *i, char **argv, int argc)
{
	(void)argc;
	if (ft_strncmp(argv[2], "--save", 7) != 0)
	{
		ft_printf("Error\n-12 : Wrong arguments.\n");
		ft_exit_program(a);
	}
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
	int		i;

	ft_memmove(a->bmp->header, "BM", 2);
	ft_memmove(a->bmp->header + 2, &a->bmp->file_s, 4);
	ft_memmove(a->bmp->header + 10, &a->bmp->header_s, 4);
	ft_memmove(a->bmp->header + 14, &a->bmp->bytes_s, 4);
	ft_memmove(a->bmp->header + 18, &a->bmp->w, 4);
	ft_memmove(a->bmp->header + 22, &a->bmp->height, 4);
	ft_memmove(a->bmp->header + 26, &a->bmp->biplanes, 4);
	ft_memmove(a->bmp->header + 28, &a->bmp->bytes_number, 4);
	ft_memmove(a->bmp->header + 34, &a->bmp->image_s, 4);
	a->bmp->fd = open("./screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	i = a->bmp->height;
	write(a->bmp->fd, a->bmp->header, 54);
	while (i != 0)
		write(a->bmp->fd, a->infos->int_img + (i-- * a->bmp->w), a->bmp->w * 4);
	close(a->bmp->fd);
	ft_printf("*Click !* Your screenshot is ready !");
}
