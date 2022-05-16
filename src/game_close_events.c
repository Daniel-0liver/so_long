/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/16 01:19:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->player.player_img != NULL)
		mlx_destroy_image(game->mlx, game->player.player_img);
	if (game->map.floor_img != NULL)
		mlx_destroy_image(game->mlx, game->map.floor_img);
	if (game->map.wall_img != NULL)
		mlx_destroy_image(game->mlx, game->map.wall_img);
}

void	close_win(t_game *game)
{
	destroy_images(game);
	game_free_memory(game);
	mlx_destroy_window(game->mlx, game->win.win_ptr);
}

void	error_event(char *error_msg, t_game *game)
{
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

void	game_free_memory(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_grid[++i])
		ft_free_ptr((void *)&game->map.map_grid[i]);
	ft_free_ptr((void *)&game->map.map_grid);
}
