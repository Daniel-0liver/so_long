/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/15 22:19:32 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	destroy_images(t_game *game)
// {
// 	if (game->floor.img != NULL)
// 		mlx_destroy_image(game->mlx, game->floor.img);
// 	if (game->wall.img != NULL)
// 		mlx_destroy_image(game->mlx, game->wall.img);
// 	if (game->exit.img != NULL)
// 		mlx_destroy_image(game->mlx, game->exit.img);
// 	if (game->collect.img != NULL)
// 		mlx_destroy_image(game->mlx, game->collect.img);
// 	if (game->step.img != NULL)
// 		mlx_destroy_image(game->mlx, game->step.img);
// 	destroy_player_trap_img(game);
// }

// void	destroy_player_trap_img(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	if (game->player.img != NULL)
// 	{
// 		while (i < 3)
// 		{
// 			if (game->player.img[i])
// 				mlx_destroy_image(game->mlx, game->player.img[i]);
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	if (game->trap.img != NULL)
// 	{
// 		while (i < 2)
// 		{
// 			if (game->trap.img[i])
// 				mlx_destroy_image(game->mlx, game->trap.img[i]);
// 			i++;
// 		}
// 	}
// }

void	close_win(t_game *game)
{
	game_free_memory(game);
	exit(0);
}

void	error_event(char *error_msg, t_game *game, int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd(error_msg, 1);
		exit(0);
	}
	ft_putstr_fd(error_msg, 1);
	close_win(game);
}

void	game_free_memory(t_game *game)
{
	char	*tmp;
	int		i;

	if (game->map.map_grid)
	{
		i = 0;
		while (*game->map.map_grid != NULL)
		{
			tmp = *game->map.map_grid;
			game->map.map_grid++;
			free(tmp);
			i++;
		}
	}
}
