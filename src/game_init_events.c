/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:35:26 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/07 01:30:29 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Start all functions to initialize the game
void	game_init(t_game *game)
{
	map_read(game);
	path_init(game);
	map_is_rectangular(game);
	map_valid_char(game);
	if (game->exit.num_e != 1)
		error_event("Error\nJust one exit is allowed", game, 0);
	if (game->player.num_p != 1)
		error_event("Error\nJust one player is allowed", game, 0);
	if (game->collect.num_c <= 0)
		error_event("Error\nMust be at least one collectible", game, 0);
	map_is_closed(game);
	window_init(game);
	img_int(game);
}

//Create a window
void	window_init(t_game *game)
{
	game->win.width = game->size_img * game->map.map_column;
	game->win.height = game->size_img * game->map.map_row;
	game->win.win_ptr = mlx_new_window(game->mlx,
		game->win.width, game->win.height, "So_long");
	if (game->win.win_ptr == NULL)
		error_event("Error\nWhile generating window", game, 0);
}

// Initialize path of all images and number of CPET
void	path_init(t_game *game)
{
	game->player.img_path = calloc(3, sizeof(char *));
	game->trap.img_path = calloc(2, sizeof(char *));
	game->player.img_path[0] = "./textures/slime_1_frame_right_64.xpm";
	game->player.img_path[1] = "./textures/slime_2_frame_right_64.xpm";
	game->player.img_path[2] = "./textures/slime_3_frame_right_64.xpm";
	game->trap.img_path[0] = "./textures/fire_1_frame_64.xpm";
	game->trap.img_path[1] = "./textures/fire_2_frame_64.xpm";
	game->collect.img_path = "./textures/diamond_64.xpm";
	game->floor.img_path = "./textures/wooden_wall_64.xpm";
	game->step.img_path = "./textures/background_steps.xpm";
	game->exit.img_path = "./textures/stair_wood_64.xpm";
	game->wall.img_path = "./textures/wall_64.xpm";
	game->player.num_moves = 0;
	game->collect.num_c = 0;
	game->player.render = 0;
	game->collect.frame = 0;
	game->player.num_p = 0;
	game->exit.num_e = 0;
	game->trap.num_t = 0;
	game->trap.frame = 0;
	game->frames = 0;
}

// Initialize all the images in the mlx
void	img_int(t_game *game)
{
	player_img_init(game);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, game->wall.img_path, 
		&game->win.width, &game->win.height);
	if (!game->wall.img)
		error_event("Erro while generating wall IMG", game, 0);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, game->floor.img_path, 
		&game->win.width, &game->win.height);
	if (!game->floor.img)
		error_event("Erro while generating floor IMG", game, 0);
	game->collect.img = mlx_xpm_file_to_image(game->mlx, 
		game->collect.img_path, &game->win.width, &game->win.height);
	if (!game->collect.img)
		error_event("Erro while generating collect IMG", game, 0);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, game->exit.img_path, 
		&game->win.width, &game->win.height);
	if (!game->exit.img)
		error_event("Erro while generating exit IMG", game, 0);
	game->step.img = mlx_xpm_file_to_image(game->mlx, game->step.img_path, 
		&game->win.width, &game->win.height);
	if (!game->step.img)
		error_event("Error while generating step IMG", game, 0);
}

// Initialize and verify player img
void	player_img_init(t_game *game)
{
	int	i;

	i = 0;
	game->player.img = calloc(3, sizeof(void *));
	while (i < 3)
	{
		game->player.img[i] = mlx_xpm_file_to_image(game->mlx, 
			game->player.img_path[i], &game->win.width, &game->win.height);
		if (!game->player.img[i])
			error_event("Erro while generating player IMG", game, 0);
		i++;
	}
	i = 0;
	game->trap.img = calloc(2, sizeof(void *));
	while (i < 2)
	{
		game->trap.img[i] = mlx_xpm_file_to_image(game->mlx, game->trap.img_path[i], 
			&game->win.width, &game->win.height);
		if (!game->trap.img[i])
			error_event("Erro while generating trap IMG", game, 0);
		i++;
	}
}
