/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/29 20:17:00 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static void	setup_level_paths(t_game *game)
{
	char	*paths[4];
	int	index;

	paths[0] = "maps/map1.ber";
	paths[1] = "maps/map2.ber";
	paths[2] = "maps/map3.ber";
	paths[3] = "maps/map4.ber";
	game->level_count = 0;
	index = 0;
	while (index < 4)
	{
		if (file_exists(paths[index]))
		{
			game->level_paths[game->level_count] = paths[index];
			game->level_count++;
		}
		index++;
	}
	if (game->level_count == 0)
		exit(printf("Error\nNo playable maps found in maps/\n") > 0);
}

static int	menu_selector(t_game *game)
{
	char	*input;
	int		choice;
	int		index;

	ft_printf("\n=== SO_LONG MENU ===\n");
	index = 0;
	while (index < game->level_count)
	{
		ft_printf("%d) %s\n", index + 1, game->level_paths[index]);
		index++;
	}
	ft_printf("Select starting map [1-%d] (Enter = 1): ", game->level_count);
	input = get_next_line(0);
	if (input == NULL || input[0] == '\n')
		return (ft_free_ptr((void *)&input), 0);
	choice = ft_atoi(input);
	ft_free_ptr((void *)&input);
	if (choice < 1 || choice > game->level_count)
		return (0);
	return (choice - 1);
}

void	next_level(t_game *game)
{
	if (game->level_index + 1 >= game->level_count)
		error_event("You finished all maps!", game, 0);
	game->level_index++;
	ft_printf("Level complete! Loading: %s\n",
		game->level_paths[game->level_index]);
	free_level_memory(game);
	input_valid(2, game->level_paths[game->level_index], game);
	game_init(game);
	get_hooks(game);
}

int	main(int argc, char	**argv)
{
	t_game	game;

	(void)argv;
	ft_bzero(&game, sizeof(t_game));
	if (argc != 1 && argc != 2)
		exit(printf("Error\nUse: ./so_long [map.ber]\n") > 0);
	setup_level_paths(&game);
	if (argc == 2)
	{
		if (!file_exists(argv[1]))
			exit(printf("Error\nIts not a valid file\n") > 0);
		game.level_paths[0] = argv[1];
		game.level_count = 1;
		game.level_index = 0;
	}
	else
		game.level_index = menu_selector(&game);
	input_valid(2, game.level_paths[game.level_index], &game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(printf("Error\nWhile initialing MLX\n") > 0);
	game_init(&game);
	get_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
