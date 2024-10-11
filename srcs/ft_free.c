/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:37 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/13 18:12:19 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//count line.s
size_t	ft_count(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

//free the lines in map
void	ft_free_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_count(map);
	while (i < j)
		free(map[i++]);
	free(map);
}

//free game - end
void	ft_free(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->y_li)
		free(game->map[i++]);
	free(game->map);
	exit(EXIT_SUCCESS);
}
