/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:55:03 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/17 16:06:02 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define PIXEL 64

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*colec;
	mlx_image_t	*exit;
	mlx_image_t	*finish;
}	t_image;

typedef struct s_game
{
	char		**map;
	int			lines;
	int			colum;
	int			item;
	int			pl_x;
	int			pl_y;
	int			ex_x;
	int			ex_y;
	int			count;
	mlx_t		*mlx;
	t_image		*image;
}	t_game;
/*-------------GNL-------------*/
char			*get_next_line(int fd);
char			*new_line(char *storage);
char			*new_storage(char *storage, char *line);
char			*free_stor(char **storage);
/*----------GNL-utils----------*/
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(char *str, int c);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(char *str);
/*----------ft_printf----------*/
int				ft_printf(char const *s, ...);
char			*tipe_finder(char c);
int				putchar_c(char c);
int				putstr_c(char *s);
int				putnbr_c(int n);
/*-----------so_long------------*/
void			my_keyhook(mlx_key_data_t keydata, void *param);
char			**create_map(char *argv, int lines);
int				count_lines(char *argv);
int				column_comp(char **map, int lines);
void			error(void);
/*-----------utils_1-----------*/
int				strlen2(char *argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			setpos_ep(t_game *game);
void			set_xy(t_game *game);
char			**copymap(t_game *game);
/*-----------utils_2-----------*/
void			end_game(t_game *game);
void			set_images(t_game *game);
void			free_map(char **map);
/*-----------map_checks-----------*/
int				map_checker(t_game *game);
int				check_colec(t_game *game);
int				check_char(t_game *game);
int				check_ep(t_game *game);
int				check_walls(t_game *game);
/*------------map_print-----------*/
void			map_print(t_game *game);
int				floodfill(t_game *game);
/*-----------set_images------------*/
mlx_texture_t	*set_img_exit(t_game *game);
mlx_texture_t	*set_img_player(t_game *game);
mlx_texture_t	*set_img_colec(t_game *game);
mlx_texture_t	*set_img_floor(t_game *game);
mlx_texture_t	*set_img_wall(t_game *game);

#endif