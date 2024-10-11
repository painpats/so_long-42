/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:34 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/14 14:09:29 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init structures
void	ft_init_struct(t_game *game)
{
	game->map = NULL;
	game->x_co = 0;
	game->y_li = 0;
	game->step = 0;
	game->bag = 0;
	game->sym.c = 0;
	game->sym.e = 0;
	game->sym.p = 0;
	game->sym.z = 0;
}

void	ft_game(t_game *game, char **map)
{
	game->map = map;
	game->mlx = mlx_init();
	ft_init_sprite(game);
	game->pwin = mlx_new_window(game->mlx, \
			game->x_co * 32, game->y_li * 32, "The Lost Coin");
	ft_visu_sprites(game);
	mlx_key_hook(game->pwin, ft_set_keycode, game);
	mlx_hook(game->pwin, 17, 0, ft_quit_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**map;

	map = NULL;
	if (argc != 2)
		merror_pber("Invalid number of arguments\n");
	else if (argc == 2)
	{
		ext_checker(argv[1], ".ber");
		map = ft_read_map(argv[1]);
		map_parsing(&game, map);
		map_check_path(map, argv[1]);
	}
	ft_game(&game, map);
	return (0);
}
