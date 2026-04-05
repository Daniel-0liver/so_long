/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/07/29 20:23:16 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **grid, int row_max, int col_max, t_coord pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.y >= row_max || pos.x >= col_max)
		return ;
	if (grid[pos.y][pos.x] == '1' || grid[pos.y][pos.x] == 'V'
		|| grid[pos.y][pos.x] == 'T')
		return ;
	grid[pos.y][pos.x] = 'V';
	flood_fill(grid, row_max, col_max, (t_coord){pos.x + 1, pos.y});
	flood_fill(grid, row_max, col_max, (t_coord){pos.x - 1, pos.y});
	flood_fill(grid, row_max, col_max, (t_coord){pos.x, pos.y + 1});
	flood_fill(grid, row_max, col_max, (t_coord){pos.x, pos.y - 1});
}

static char	**copy_map_grid(t_game *game)
{
	char	**copy;
	int		row;
	int		col;

	copy = calloc(game->map.map_row + 1, sizeof(char *));
	if (!copy)
		error_event("Error\nWhile allocating playable map", game, 0);
	row = 0;
	while (row < game->map.map_row)
	{
		copy[row] = calloc(game->map.map_column + 1, sizeof(char));
		if (!copy[row])
			error_event("Error\nWhile allocating playable map", game, 0);
		col = 0;
		while (col < game->map.map_column)
		{
			copy[row][col] = game->map.map_grid[row][col];
			col++;
		}
		row++;
	}
	return (copy);
}

static void	free_map_copy(char **grid)
{
	int	row;

	row = 0;
	while (grid[row])
	{
		ft_free_ptr((void *)&grid[row]);
		row++;
	}
	ft_free_ptr((void *)&grid);
}

void	map_is_playable(t_game *game)
{
	char	**grid_copy;
	int		row;
	int		col;

	grid_copy = copy_map_grid(game);
	flood_fill(grid_copy, game->map.map_row, game->map.map_column,
		(t_coord){game->player.coord.x / game->size_img,
		game->player.coord.y / game->size_img});
	row = 0;
	while (row < game->map.map_row)
	{
		col = 0;
		while (col < game->map.map_column)
		{
			if (grid_copy[row][col] == 'C' || grid_copy[row][col] == 'E')
			{
				free_map_copy(grid_copy);
				error_event("Error\nMap is not playable", game, 0);
			}
			col++;
		}
		row++;
	}
	free_map_copy(grid_copy);
}

// Read the map file and generate a matrix with the lines of the file
void	map_read(t_game *game)
{
	int		fd;
	int		i;

	fd = open(game->map.map_path, O_RDONLY);
	if (fd < 0)
		error_event("Error\nWhile opening file", game, 1);
	i = 0;
	game->map.map_grid = calloc(50, sizeof(char *));
	if (game->map.map_grid == NULL)
		error_event("Error\nWhile allocating memory for map", game, 1);
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
		error_event("Error\nMap Must be Retangular!", game, 1);
	i = 0;
	while (game->map.map_grid[i])
	{
		if (ft_strlen(game->map.map_grid[i])
			!= (size_t)(game->map.map_column + 1))
			if ((i + 1) != game->map.map_row)
				error_event("Error\nMap size invalid", game, 1);
		i++;
	}
	if (ft_strlen(game->map.map_grid[game->map.map_row - 1])
		!= (size_t)game->map.map_column)
		error_event("Error\nMap size invalid", game, 1);
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
	int	k;

	i = 0;
	game->trap.num_t = 0;
	while (i < game->map.map_row)
	{
		j = 0;
		while (j < game->map.map_column)
		{
			if (game->map.map_grid[i][j] == 'T')
				game->trap.num_t += 1;
			if ((i == 0 || i == (game->map.map_row - 1))
				&& game->map.map_grid[i][j] != '1')
				error_event("Error\nMap must be surrounded by walls", game, 0);
			if ((j == 0 || j == (game->map.map_column - 1))
				&& game->map.map_grid[i][j] != '1')
				error_event("Error\nMap must be surrounded by walls", game, 0);
			j++;
		}
		i++;
	}
	if (game->trap.num_t == 0)
		return ;
	game->trap.coord = calloc(game->trap.num_t, sizeof(t_coord));
	game->trap.dir = calloc(game->trap.num_t, sizeof(int));
	if (!game->trap.coord || !game->trap.dir)
		error_event("Error\nWhile allocating memory for traps", game, 0);
	k = 0;
	i = 0;
	while (i < game->map.map_row)
	{
		j = 0;
		while (j < game->map.map_column)
		{
			if (game->map.map_grid[i][j] == 'T')
			{
				game->trap.coord[k].x = j;
				game->trap.coord[k].y = i;
				game->trap.dir[k] = 1;
				k++;
			}
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
	{
		game->collect.num_c += 1;
		game->collect.total_c += 1;
	}
	if (c == 'P')
	{
		game->player.num_p += 1;
		game->player.coord.x = (j * game->size_img);
		game->player.coord.y = (i * game->size_img);
		game->map.map_grid[i][j] = '0';
	}
}
