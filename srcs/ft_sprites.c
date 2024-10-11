/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:56:26 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/13 18:53:24 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init the sprites
void	ft_init_sprite(t_game *game)
{
	int	size;

	game->sprite.floor = mlx_xpm_file_to_image(game->mlx, \
			"./xpm/floor.xpm", &size, &size);
	game->sprite.wall = mlx_xpm_file_to_image(game->mlx, \
			"./xpm/wall.xpm", &size, &size);
	game->sprite.collectible = mlx_xpm_file_to_image(game->mlx, \
			"./xpm/collectible.xpm", &size, &size);
	game->sprite.exit = mlx_xpm_file_to_image(game->mlx, \
			"./xpm/exit.xpm", &size, &size);
	game->sprite.player = mlx_xpm_file_to_image(game->mlx, \
			"./xpm/player.xpm", &size, &size);
}

// put the images on the window
void	ft_put_image_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprite.player, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprite.exit, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprite.collectible, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprite.wall, x * 32, y * 32);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprite.floor, x * 32, y * 32);
}

// show the sprites on the window
void	ft_visu_sprites(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			ft_put_image_to_window(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

// destroy image and free game
int	ft_quit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.player);
	mlx_destroy_image(game->mlx, game->sprite.collectible);
	mlx_destroy_image(game->mlx, game->sprite.wall);
	mlx_destroy_image(game->mlx, game->sprite.floor);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	mlx_destroy_window(game->mlx, game->pwin);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game);
	return (0);
}
