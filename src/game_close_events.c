/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/04 18:13:18 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->collect.img)
		mlx_destroy_image(game->mlx, game->collect.img);
	if (game->step.img)
		mlx_destroy_image(game->mlx, game->step.img);
	destroy_player_trap_img(game);
}

void	destroy_player_trap_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->player.img[i])
			mlx_destroy_image(game->mlx, game->player.img[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game->trap.img[i])
			mlx_destroy_image(game->mlx, game->trap.img[i]);
		i++;
	}
}

void	close_win(t_game *game)
{
	destroy_images(game);
	game_free_memory(game);
	// mlx_destroy_window(game->mlx, game->win.win_ptr);
	// mlx_destroy_display(game->mlx);
	exit(0);
}

void	error_event(char *error_msg, t_game *game)
{
	perror(error_msg);
	close_win(game);
}

void	game_free_memory(t_game *game)
{
	char	**grid;
	char	*tmp;
	int		i;

	grid = game->map.map_grid;
	i = 0;
	while (*game->map.map_grid != NULL)
	{
		tmp = *game->map.map_grid;
		game->map.map_grid++;
		free(tmp);
		i++;
	}
	ft_free_ptr((void *)&game->player.img);
	ft_free_ptr((void *)&game->player.img_path);
	ft_free_ptr((void *)&game->trap.img_path);
	ft_free_ptr((void *)&game->trap.img);
	ft_free_ptr((void *)&game->step.step_str);
}
