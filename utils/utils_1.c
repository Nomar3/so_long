/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarin-j <rmarin-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:32:42 by rmarin-j          #+#    #+#             */
/*   Updated: 2024/05/14 18:02:44 by rmarin-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n != 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}

int	strlen2(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	set_xy(t_game *game)
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
			if (game->map[i][j] == 'E')
			{
				game->ex_x = i;
				game->ex_y = j;
			}
			if (game->map[i][j] == 'P')
			{
				game->pl_x = i;
				game->pl_y = j;
			}
			j++;
		}
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		n;
	int		i;
	char	*ptr;
	char	*aux;

	aux = (char *)s1;
	i = 0;
	n = ft_strlen(aux) + 1;
	if (!s1)
		return (0);
	ptr = (char *)malloc(sizeof (char) * n);
	if (!ptr)
		return (0);
	while (aux[i])
	{
		ptr[i] = aux[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**copymap(t_game *game)
{
	int		i;
	char	**cmap;

	i = 0;
	cmap = malloc(sizeof(char *) * (game->lines + 1));
	while (game->map[i])
	{
		cmap[i] = ft_strdup(game->map[i]);
		i++;
	}
	cmap[i] = NULL;
	return (cmap);
}
