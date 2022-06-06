/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/07 00:28:21 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Read the map file and generate a matrix with the lines of the file
void	map_read(t_game *game)
{
	int		fd;
	int		i;
	
	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		error_event("Error\nWhile opening file", game, 1);
	i = 0;
	while (game->map.map_grid != NULL)
	{
		game->map.map_grid[i] = get_next_line(fd);
		if (i == 0 && game->map.map_grid[i] == NULL)
			error_event("Error\nMap is empty", game, 1);
		if (game->map.map_grid[i] == NULL)
			return ;
		i++;
	}
}

// Check if the map is rectangular
void	map_is_rectangular(t_game *game)
{
	int	i;
	
	i = 0;
	while (game->map.map_grid[i])
		i++;
	game->map.map_row = i;
	i = 0;
	while (game->map.map_grid[0][i])
		i++;
	game->map.map_column = i - 1;
	if (game->map.map_row == game->map.map_column)
		error_event("Error\nMap Must be Retangular!", game, 0);
	i = 0;
	while (game->map.map_grid[i])
	{
		if (ft_strlen(game->map.map_grid[i]) != (game->map.map_column + 1))
		{
			printf("%d, %d\n", i, game->map.map_row);
			if (i != game->map.map_row)
				error_event("Error\nMap size invalid", game, 0);
		}
		i++;
	}
}

// Check if the map has some not allowed char
void	map_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map_grid[i])
	{
		j = 0;
		while (game->map.map_grid[i][j])
		{
			if (game->map.map_grid[i][j] == 'E')
				char_valid_event(game, i, j, 'E');
			if (game->map.map_grid[i][j] == 'C')
				char_valid_event(game, i, j, 'C');
			if (game->map.map_grid[i][j] == 'P')
				char_valid_event(game, i, j, 'P');
			if (game->map.map_grid[i][j] != '\n' && !ft_strchr
				(game->valid_char, game->map.map_grid[i][j]))
				error_event("Error\nInvalid char", game, 0);
			j++;
		}
		i++;
	}
}

// Check if the map is surrounded by walls
void	map_is_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_row)
	{
		j = 0;
		while (j < game->map.map_column)
		{
			if (game->map.map_grid[i][j] == 'T')
				game->trap.num_t += 1;
			if ((i == 0 || i == (game->map.map_row - 1)) && 
				game->map.map_grid[i][j] != '1')
				error_event("Error\nMap must be surrounded by walls", game, 0);
			if ((j == 0 || j == (game->map.map_column - 1)) && 
				game->map.map_grid[i][j] != '1')
				error_event("Error\nMap must be surrounded by walls", game, 0);
			j++;
		}
		i++;
	}
}

void	char_valid_event(t_game *game, int i, int j, char c)
{
	if (c == 'E')
	{
		game->exit.num_e += 1;
		game->exit.coord.x = (j * game->size_img);
		game->exit.coord.y = (i * game->size_img);
	}
	if (c == 'C')
		game->collect.num_c += 1;
	if (c == 'P')
	{
		game->player.num_p += 1;
		game->player.coord.x = (j * game->size_img);
		game->player.coord.y = (i * game->size_img);
	}
}