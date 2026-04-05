/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/23 00:04:57 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_level_memory(t_game *game)
{
	int	i;

	if (game->mlx != NULL)
		destroy_images(game);
	if (game->player.img != NULL)
		ft_free_ptr((void *)&game->player.img);
	if (game->trap.img != NULL)
		ft_free_ptr((void *)&game->trap.img);
	if (game->trap.coord != NULL)
		ft_free_ptr((void *)&game->trap.coord);
	if (game->trap.dir != NULL)
		ft_free_ptr((void *)&game->trap.dir);
	if (game->player.img_path != NULL)
		ft_free_ptr((void *)&game->player.img_path);
	if (game->trap.img_path != NULL)
		ft_free_ptr((void *)&game->trap.img_path);
	if (game->win.win_ptr != NULL)
		mlx_destroy_window(game->mlx, game->win.win_ptr);
	game->win.win_ptr = NULL;
	if (game->map.map_grid != NULL)
	{
		i = 0;
		while (game->map.map_grid[i])
			ft_free_ptr((void *)&game->map.map_grid[i++]);
		ft_free_ptr((void *)&game->map.map_grid);
	}
}

void	destroy_images(t_game *game)
{
	if (game->floor.img != NULL)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->exit.img != NULL)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->collect.img != NULL)
		mlx_destroy_image(game->mlx, game->collect.img);
	if (game->step.img != NULL)
		mlx_destroy_image(game->mlx, game->step.img);
	destroy_player_trap_img(game);
}

void	destroy_player_trap_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->player.img[i] != NULL)
			mlx_destroy_image(game->mlx, game->player.img[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (game->trap.img[i] != NULL)
			mlx_destroy_image(game->mlx, game->trap.img[i]);
		i++;
	}
}

void	close_win(t_game *game)
{
	free_level_memory(game);
	game_free_memory(game);
	exit(0);
}

void	error_event(char *error_msg, t_game *game, int error_code)
{
	ft_putstr_fd(error_msg, 1);
	ft_printf("\n");
	(void)error_code;
	close_win(game);
}

void	game_free_memory(t_game *game)
{
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	if (game->mlx != NULL)
		ft_free_ptr((void *)&game->mlx);
}
