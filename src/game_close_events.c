/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/04 14:56:26 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->player.img != NULL)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->floor.img != NULL)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img != NULL)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->collect.img != NULL)
		mlx_destroy_image(game->mlx, game->collect.img);
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
	// close_win(game);
	exit(0);
}

void	game_free_memory(t_game *game)
{
	ft_free_array((void ***)&game->map.map_grid);
	ft_free_array((void ***)&game->player.img_path);
	ft_free_array(&game->player.img);
	ft_free_array((void ***)&game->trap.img_path);
	ft_free_array(&game->trap.img);
	ft_free_ptr((void *)&game->step.step_str);
}
