/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:40:22 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/10 22:41:45 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_destroy_image.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:45:54 2007 Olivier Crouzet
*/

#include "mlx_int.h"

int	mlx_destroy_image(t_xvar *xvar, t_img *img)
{
	if (img->type == MLX_TYPE_SHM_PIXMAP
		||img->type == MLX_TYPE_SHM)
	{
		XShmDetach(xvar->display, &(img->shm));
		shmdt(img->shm.shmaddr);
	}
	XDestroyImage(img->image);
	XFreePixmap(xvar->display, img->pix);
	if (img->gc)
		XFreeGC(xvar->display, img->gc);
	free(img);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
