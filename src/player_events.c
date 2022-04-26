/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:33:50 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/27 00:20:31 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_right(t_game *game)
{
	game->player->player_pos_x += 10;
	return ; 
}

void	player_move_left(t_game *game)
{
	game->player->player_pos_x -= 10;
	return ; 
}

void	player_move_up(t_game *game)
{
	game->player->player_pos_y -= 10;
	return ; 
}

void	player_move_down(t_game *game)
{
	game->player->player_pos_y += 10;
	return ; 
}