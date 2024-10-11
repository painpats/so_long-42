/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:22 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/14 14:20:59 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check that the map is surrounded by walls
void	check_external_walls(t_game *game, char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if ((y == 0 || y == game->y_li - 1) && map[y][x] != '1')
				merror_pars("The map must be surrounded by walls\n", map);
			if ((x == 0 || x == game->x_co - 1) && map[y][x] != '1')
				merror_pars("The map must be surrounded by walls\n", map);
			x++;
		}
		x = 0;
		y++;
	}
}

// check symbol : P = 1, E = 1, C > 0
void	check_symbol(t_game *game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				game->sym.c += 1;
			else if (map[y][x] == 'E')
				game->sym.e += 1;
			else if (map[y][x] == 'P')
				game->sym.p += 1;
			else if (map[y][x] == '0')
				game->sym.z += 1;
			else if (map[y][x] != '1')
				merror_pars("Invalid symbol.s (CEP01)\n", map);
		}
		x = 0;
	}
	if (game->sym.c < 1 || game->sym.e != 1 || game->sym.p != 1)
		merror_pars("Invalid symbol.s CEP01\n", map);
}

// check if map rectangle, has external wall and the right amount of symbols
void	map_parsing(t_game *game, char **map)
{
	size_t	i;

	i = 1;
	ft_init_struct(game);
	game->x_co = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != game->x_co)
			merror_pars("The map must be rectangular\n", map);
		i++;
	}
	game->y_li = i;
	check_external_walls(game, map);
	check_symbol(game, map);
}
