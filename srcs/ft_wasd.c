/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:07:35 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/13 19:11:05 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init keycode 
int	ft_set_keycode(int keycode, t_game *game)
{
	if (keycode == ESC)
	{	
		ft_quit_game(game);
		return (0);
	}
	else if (keycode == W)
		ft_up(game);
	else if (keycode == A)
		ft_left(game);
	else if (keycode == S)
		ft_down(game);
	else if (keycode == D)
		ft_right(game);
	return (0);
}

// W - up
void	ft_up(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_player(game, (y - 1), x) == -1)
					game->map[y][x] = 'P';
				ft_visu_sprites(game);
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_visu_sprites(game);
}

// A - left
void	ft_left(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_player(game, y, (x - 1)) == -1)
					game->map[y][x] = 'P';
				ft_visu_sprites(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_visu_sprites(game);
}

// S - down
void	ft_down(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_player(game, (y + 1), x) == -1)
					game->map[y][x] = 'P';
				ft_visu_sprites(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_visu_sprites(game);
}

// D - right
void	ft_right(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_player(game, y, (x + 1)) == -1)
					game->map[y][x] = 'P';
				ft_visu_sprites(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_visu_sprites(game);
}
