/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:36:03 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/28 01:23:31 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\nKeycode = %d\n", keycode);
	if (keycode == 65307 || keycode == 113)
		close_win(game);
	if (keycode == 100 || keycode == 65363)
		player_move_right(game);
	if (keycode == 97 || keycode == 65361)
		player_move_left(game);
	if (keycode == 119 || keycode == 65362)
		player_move_up(game);
	if (keycode == 115 || keycode == 65364)
		player_move_down(game);
	return (0);
}

void	get_hooks(t_game *game)
{
	mlx_hook(game->win->win_ptr, DestroyNotify, NoEventMask, &close_win, &game);
	mlx_hook(game->win->win_ptr, KeyPress, KeyPressMask, &key_hook, game);
	mlx_loop_hook(game->mlx, &win_render, game);
	return ;
}