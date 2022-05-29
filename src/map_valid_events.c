/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/28 22:35:48 by dateixei         ###   ########.fr       */
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
		error_event("Error while opening file", game);
	game->map.map_grid = ft_calloc(1, sizeof(char**));
	if (game->map.map_grid == NULL)
		error_event("Error while allocating memory for map", game);
	i = 0;
	while (game->map.map_grid != NULL)
	{
		game->map.map_grid[i] = get_next_line(fd);
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
		error_event("Error Map Must be Retangular!", game);
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
				game->exit.num_e += 1;
			if (game->map.map_grid[i][j] == 'C')
				game->collect.num_c += 1;
			if (game->map.map_grid[i][j] == 'P')
				game->player.num_p += 1;
			if (game->map.map_grid[i][j] != '\n' && !ft_strchr
				(game->valid_char, game->map.map_grid[i][j]))
				error_event("Invalid char", game);
			j++;
		}
		if (j - 1 != game->map.map_column)
			error_event("Erro map size invalid", game);
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
			if ((i == 0 || i == (game->map.map_row - 1)) && 
				game->map.map_grid[i][j] != '1')
				error_event("Error map must be surrounded by  walls", game);
			if ((j == 0 || j == (game->map.map_column - 1)) && 
				game->map.map_grid[i][j] != '1')
				error_event("Error map must be surrounded by  walls", game);
			if (game->map.map_grid[i][j] == 'P')
			{
				game->player.coord.x = (j * game->size_img);
				game->player.coord.y = (i * game->size_img);
			}
			j++;
		}
		i++;
	}
}