/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:03:17 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/22 00:53:27 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_init(t_game *game)
{
	game->win->height = 100;
	game->win->width = 100;
	game->win->win_ptr = mlx_new_window(game->mlx, game->win->height, game->win->width, "teste");
	return ;
}