/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:06:57 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/21 00:08:44 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_game *game)
{
	puts("destroy images begin");
	if (game->floor.img != NULL)
		mlx_destroy_image(game->mlx, game->floor.img);
	puts("destroy images after floor");
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	puts("destroy images after wall");
	if (game->exit.img != NULL)
		mlx_destroy_image(game->mlx, game->exit.img);
	puts("destroy images after exit");
	if (game->collect.img != NULL)
		mlx_destroy_image(game->mlx, game->collect.img);
	puts("destroy images after collect");
	if (game->step.img != NULL)
		mlx_destroy_image(game->mlx, game->step.img);
	puts("destroy images after step");
	destroy_player_trap_img(game);
	puts("destroy images after destroy player img");
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
	puts("close_game begin");
	destroy_images(game);
	puts("close_game after destroy images");
	if (game->player.img != NULL)
		ft_free_ptr((void *)&game->player.img);
	if (game->trap.img != NULL)
		ft_free_ptr((void *)&game->trap.img);
	if (game->player.img_path != NULL)
		ft_free_ptr((void *)&game->player.img_path);
	if (game->trap.img_path != NULL)
		ft_free_ptr((void *)&game->trap.img_path);
	if (game->win.win_ptr != NULL)
		mlx_destroy_window(game->mlx, game->win.win_ptr);
	game_free_memory(game);
	exit(0);
}

void	error_event(char *error_msg, t_game *game, int error_code)
{
	if (error_code >= 1)
	{
		game_free_memory(game);
		ft_putstr_fd(error_msg, 1);
		ft_printf("\n");
		exit(0);
	}
	ft_putstr_fd(error_msg, 1);
	ft_printf("\n");
	close_win(game);
}

void	game_free_memory(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_grid[i])
		ft_free_ptr((void *)&game->map.map_grid[i++]);
	ft_free_ptr((void *)&game->map.map_grid);
	mlx_destroy_display(game->mlx);
	ft_free_ptr((void *)&game->mlx);
}
