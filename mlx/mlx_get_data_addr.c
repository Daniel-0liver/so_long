/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_data_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:54:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/10 22:55:08 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_get_data_addr.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:45:57 2000 Charlie Root
** Last update Thu Sep 27 19:05:25 2001 Charlie Root
*/

#include	"mlx_int.h"

char	*mlx_get_data_addr(t_img *img, int *bits_per_pixel,
	int *size_line, int *endian)
{
	*bits_per_pixel = img->bpp;
	*size_line = img->size_line;
	*endian = img->image->byte_order;
	return (img->data);
}
