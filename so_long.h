/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:55:03 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/04/30 20:11:14 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 1
#  endif

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
	mlx_t		*mlx;
}	t_game;
/*-------------GNL-------------*/
char	*get_next_line(int fd);
char	*new_line(char *storage);
char	*new_storage(char *storage, char *line);
char	*free_stor(char **storage);
/*----------GNL-utils----------*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
/*-----------so_long------------*/
char	**create_map(char *argv, int lines);
int		count_lines(char *argv);
int		column_comp(char **map, int lines);
void	error();
/*-----------utils-----------*/
int		strlen2(char *argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*-----------map_checks-----------*/
int		map_checker(t_game *game);
int		check_colec(t_game *game);
int		check_char(t_game *game);
int		check_ep(t_game *game);
int		check_walls(t_game *game);

#endif