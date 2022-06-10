/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_flush_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:25 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/10 22:49:55 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx_flush_event.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Aug  2 18:58:11 2000 Charlie Root
** Last update Fri Feb 23 17:08:48 2001 Charlie Root
*/

#include "mlx_int.h"

int	mlx_flush_event(t_xvar *xvar)
{
	XEvent	ev;

	while (XPending(xvar->display))
	{
		XNextEvent(xvar->display, &ev);
	}
}
