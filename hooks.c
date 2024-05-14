/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:05:30 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 17:52:11 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_a(t_game *game)
{
	if (game->map[game->pl_y][game->pl_x - 1] != '1')
	{
		if (game->map[game->pl_y][game->pl_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->pl_x --;
		mlx_image_to_window(game->mlx, game->image->player,
			game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->pl_y][game->pl_x] == 'C')
		{
			game->item--;
			game->map[game->pl_y][game->pl_x] = '0';
			if (game->item == 0)
				mlx_image_to_window(game->mlx, game->image->finish,
					game->ex_y * PIXEL, game->ex_x * PIXEL);
		}
		if (game->map[game->pl_y][game->pl_x] == 'E' && game->item == 0)
			end_game(game);
	}
}

void	press_d(t_game *game)
{
	if (game->map[game->pl_y][game->pl_x + 1] != '1')
	{
		if (game->map[game->pl_y][game->pl_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->pl_x ++;
		mlx_image_to_window(game->mlx, game->image->player,
			game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->pl_y][game->pl_x] == 'C')
		{
			game->item--;
			game->map[game->pl_y][game->pl_x] = '0';
			if (game->item == 0)
				mlx_image_to_window(game->mlx, game->image->finish,
					game->ex_y * PIXEL, game->ex_x * PIXEL);
		}
		if (game->map[game->pl_y][game->pl_x] == 'E' && game->item == 0)
			end_game(game);
	}
}

void	press_s(t_game *game)
{
	if (game->map[game->pl_y + 1][game->pl_x] != '1')
	{
		if (game->map[game->pl_y][game->pl_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->pl_y ++;
		mlx_image_to_window(game->mlx, game->image->player,
			game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->pl_y][game->pl_x] == 'C')
		{
			game->item--;
			game->map[game->pl_y][game->pl_x] = '0';
			if (game->item == 0)
				mlx_image_to_window(game->mlx, game->image->finish,
					game->ex_y * PIXEL, game->ex_x * PIXEL);
		}
		if (game->map[game->pl_y][game->pl_x] == 'E' && game->item == 0)
			end_game(game);
	}
}

void	press_w(t_game *game)
{
	if (game->map[game->pl_y - 1][game->pl_x] != '1')
	{
		if (game->map[game->pl_y][game->pl_x] == 'E')
			mlx_image_to_window(game->mlx, game->image->exit,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->pl_y --;
		mlx_image_to_window(game->mlx, game->image->player,
			game->pl_x * PIXEL, game->pl_y * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->pl_y][game->pl_x] == 'C')
		{
			game->item--;
			game->map[game->pl_y][game->pl_x] = '0';
			if (game->item == 0)
				mlx_image_to_window(game->mlx, game->image->finish,
					game->ex_y * PIXEL, game->ex_x * PIXEL);
		}
		if (game->map[game->pl_y][game->pl_x] == 'E' && game->item == 0)
			end_game(game);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		press_w(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		press_s(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		press_a(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		press_d(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		end_game(game);
}
