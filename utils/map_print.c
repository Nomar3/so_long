/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:34:23 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/17 16:16:42 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	char_to_image(t_game *game, int i, int j)
{
	mlx_image_to_window(game->mlx, game->image->floor,
		j * PIXEL, i * PIXEL);
	if (game->map[i][j] == '1')
		mlx_image_to_window(game->mlx, game->image->wall,
			j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->image->colec,
			j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'E')
		mlx_image_to_window(game->mlx, game->image->exit,
			j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'P')
	{
		game->pl_x = j;
		game->pl_y = i;
	}
}

void	map_print(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->colum)
		{
			char_to_image(game, i, j);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->image->player,
		game->pl_x * PIXEL, game->pl_y * PIXEL);
}

static void	fill(char **map, int lines, int colum)
{
	map[lines][colum] = '1';
	if (map[lines - 1][colum] != '1')
		fill(map, (lines - 1), colum);
	if (map[lines + 1][colum] != '1')
		fill(map, (lines + 1), colum);
	if (map[lines][colum - 1] != '1')
		fill(map, lines, (colum -1));
	if (map[lines][colum + 1] != '1')
		fill(map, lines, (colum + 1));
}

int	floodfill(t_game *game)
{
	char	**cmap;
	int		i;
	int		j;

	cmap = copymap(game);
	fill(cmap, game->pl_x, game->pl_y);
	i = 0;
	j = 0;
	while (cmap[i][j])
	{
		j = 0;
		while (cmap [i][j] != '\n' && cmap[i][j] != '\0')
		{
			if (cmap[i][j] == 'C' || cmap[i][j] == 'E')
				error();
			j++;
		}
		i++;
	}
	free_map(cmap);
	return (1);
}
