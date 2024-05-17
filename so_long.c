/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:54:05 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/17 16:03:19 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	column_comp(char **map, int lines)
{
	int	i;
	int	j;

	i = 1;
	j = strlen2(map[0]);
	while (i < lines)
	{
		if (strlen2(map[i]) != j)
			error();
		i++;
	}
	return (j);
}

int	count_lines(char *argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**create_map(char *argv, int lines)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = NULL;
	map = malloc((sizeof(char *)) * (lines + 1));
	if (map == NULL)
		return (0);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || (ft_strncmp(".ber", &argv[1][strlen2(argv[1]) - 4], 4)))
		error();
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	game->count = 0;
	game->lines = count_lines(argv[1]);
	game->map = create_map(argv[1], game->lines);
	game->colum = column_comp(game->map, game->lines);
	set_xy(game);
	map_checker(game);
	game->mlx = mlx_init(game->colum * PIXEL, game->lines * PIXEL,
			"so_long", false);
	game->image = malloc(sizeof(t_image));
	if (!game->image)
		return (0);
	set_images(game);
	map_print(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	return (0);
}
	//write (1, "entra1\n", 8);
