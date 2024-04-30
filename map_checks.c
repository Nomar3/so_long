/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:25:29 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/30 20:43:15 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//mira si el exterior esta lleno de cuadrados
int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i] != '\n' && game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1' || game->map[game->lines - 1][i] != '1')
			error();
		i++;
	}
	i = 0;
	while (game->lines > (i + 1))
	{
		if (game->map[i][0] != '1' || game->map[i][game->colum - 1] != '1')
		{
			write (1, "entra if 2\n", 11);
			error();
		}
		i++;
	}
	return (1);
}

//esto mira que solo haya una e y una p
int	check_ep(t_game *game)
{
	int	e_count;
	int	p_count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	e_count = 0;
	p_count = 0;
	while (game->map[i][j])
	{
		j = 0;
		while (game->map [i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				e_count++;
			if (game->map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	if (e_count != 1 || p_count != 1)
		error();
	return (1);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j])
	{
		j = 0;
		while (game->map [i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1' || game->map[i][j] == '0'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'P')
				j++;
			else
				error();
		}
		i++;
	}
	return (1);
}

int	check_colec(t_game *game)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	j = 0;
	c_count = 0;
	while (game->map[i][j])
	{
		j = 0;
		while (game->map [i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (c_count == 0)
		error();
	return (c_count);
}

int	map_checker(t_game *game)
{
	check_char(game);
	check_walls(game);
	check_ep(game);
	game->item = check_colec(game);
	return (1);
}
