/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:54:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/24 13:21:03 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\nKeycode = %d\n", keycode);
	if (keycode == 65307 || keycode == 113)
		close_win(game);
	return (0);
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win->win_ptr);
	game->win->win_ptr = NULL;
	exit(0);
}