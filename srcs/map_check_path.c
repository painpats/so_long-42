/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:18 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/13 18:33:42 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check the surrounding (left, up, down, right)
char	**check_surrounding(char **tmp, size_t y, size_t x)
{
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'x' && tmp[y][x - 1] != 'o' \
			&& tmp[y][x - 1] != 'E')
		tmp[y][x - 1] = 'o';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'x' && tmp[y][x + 1] != 'o' \
			&& tmp[y][x + 1] != 'E')
		tmp[y][x + 1] = 'o';
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'x' && tmp[y - 1][x] != 'o' \
			&& tmp[y - 1][x] != 'E')
		tmp[y - 1][x] = 'o';
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'x' && tmp[y + 1][x] != 'o' \
			&& tmp[y + 1][x] != 'E')
		tmp[y + 1][x] = 'o';
	return (tmp);
}

// check if the player can win the game
void	check_exit(char **map, char **pos_p, size_t y, size_t x)
{
	if (pos_p[y][x - 1] == 'x' || pos_p[y][x + 1] == 'x' \
	|| pos_p[y - 1][x] == 'x' || pos_p[y + 1][x] == 'x')
		return ;
	else
	{
		ft_free_map(map);
		merror_pars("Invalid path", pos_p);
	}
}

// check if we can end the game (exit path)
void	check_end_path(char **map, char **tmp)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'C')
			{
				ft_free_map(map);
				merror_pars("Invalid path\n", tmp);
			}
			else if (tmp[y][x] == 'E')
				check_exit(map, tmp, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

// check path
void	map_check_path(char **map, char *pber)
{
	char	**tmp;
	size_t	x;
	size_t	y;

	x = 0;
	y = 1;
	tmp = ft_read_map(pber);
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'P' || tmp[y][x] == 'o')
			{
				tmp[y][x] = 'x';
				tmp = check_surrounding(tmp, y, x);
				y = 0;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	check_end_path(map, tmp);
	ft_free_map(tmp);
}
