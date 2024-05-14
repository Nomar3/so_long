/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:20:01 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 18:04:16 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_game *game)
{
	free_map(game->map);
	mlx_terminate(game->mlx);
	exit(0);
}

mlx_texture_t	*set_img_finish(t_game *game)
{
	mlx_texture_t	*a_finish;

	a_finish = mlx_load_png("./png/finish.png");
	if (!a_finish)
		error();
	game->image->finish = mlx_texture_to_image(game->mlx, a_finish);
	mlx_delete_texture(a_finish);
	if (!game->image->finish)
		error();
	return (a_finish);
}

void	set_images(t_game *game)
{
	set_img_floor(game);
	set_img_wall(game);
	set_img_exit(game);
	set_img_colec(game);
	set_img_player(game);
	set_img_finish(game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
