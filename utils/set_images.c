/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:57:23 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 17:30:51 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_texture_t	*set_img_wall(t_game *game)
{
	mlx_texture_t	*a_wall;

	a_wall = mlx_load_png("./png/wall.png");
	if (!a_wall)
		error();
	game->image->wall = mlx_texture_to_image(game->mlx, a_wall);
	mlx_delete_texture(a_wall);
	if (!game->image->wall)
		error();
	return (a_wall);
}

mlx_texture_t	*set_img_floor(t_game *game)
{
	mlx_texture_t	*a_floor;

	a_floor = mlx_load_png("./png/floor.png");
	if (!a_floor)
		error();
	game->image->floor = mlx_texture_to_image(game->mlx, a_floor);
	mlx_delete_texture(a_floor);
	if (!game->image->floor)
		error();
	return (a_floor);
}

mlx_texture_t	*set_img_colec(t_game *game)
{
	mlx_texture_t	*a_colec;

	a_colec = mlx_load_png("./png/colec.png");
	if (!a_colec)
		error();
	game->image->colec = mlx_texture_to_image(game->mlx, a_colec);
	mlx_delete_texture(a_colec);
	if (!game->image->colec)
		error();
	return (a_colec);
}

mlx_texture_t	*set_img_player(t_game *game)
{
	mlx_texture_t	*a_player;

	a_player = mlx_load_png("./png/player.png");
	if (!a_player)
		error();
	game->image->player = mlx_texture_to_image(game->mlx, a_player);
	mlx_delete_texture(a_player);
	if (!game->image->player)
		error();
	return (a_player);
}

mlx_texture_t	*set_img_exit(t_game *game)
{
	mlx_texture_t	*a_exit;

	a_exit = mlx_load_png("./png/exit.png");
	if (!a_exit)
		error();
	game->image->exit = mlx_texture_to_image(game->mlx, a_exit);
	mlx_delete_texture(a_exit);
	if (!game->image->exit)
		error();
	return (a_exit);
}

//sprites filetype:png imagesize:64x64