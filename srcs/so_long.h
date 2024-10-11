/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:31:46 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/14 16:05:49 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// Keyboard : W (up), A (left), S (down), D (right), ESC (close window)
# define W		119
# define A		97
# define S		115
# define D		100
# define ESC	65307

// Symbols : C (collectible), E (exit), P (player's position), 0 (empty)
typedef struct s_sym
{
	int	c;
	int	e;
	int	p;
	int	z;
}	t_sym;

// Sprites : Floor (0), Wall (1), Collectible (C), Exit (E), Player (P)
typedef struct s_sprite
{
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
}						t_sprite;

// Game : x_co (map column), y_li (map line)
typedef struct s_game
{
	void		*mlx;
	void		*pwin;
	char		**map;
	size_t		x_co;
	size_t		y_li;
	size_t		step;
	int			bag;
	t_sym		sym;
	t_sprite	sprite;
}						t_game;

//so_long
void	ft_game(t_game *game, char **map);
void	ft_init_struct(t_game *game);

//ext_checker
void	ext_checker(char *file, char *ext);

//map_check_path
char	**check_surrounding(char **tmp, size_t y, size_t x);
void	check_exit(char **map, char **pos_p, size_t y, size_t x);
void	check_end_path(char **map, char **tmp);
void	map_check_path(char **map, char *pber);

//map_parsing
void	check_external_walls(t_game *game, char **map);
void	check_symbol(t_game *game, char **map);
void	map_parsing(t_game *game, char **map);

//read_map
char	**ft_read_map(char *pber);
int		ft_player(t_game *game, int x, int y);

//ft_sprites
void	ft_init_sprite(t_game *game);
void	ft_put_image_to_window(t_game *game, int x, int y);
void	ft_visu_sprites(t_game *game);
int		ft_quit_game(t_game *game);

//ft_wasd
int		ft_set_keycode(int keycode, t_game *game);
void	ft_up(t_game *game);
void	ft_left(t_game *game);
void	ft_down(t_game *game);
void	ft_right(t_game *game);

//message_error
void	merror_pber(char *str);
void	merror_pars(char *str, char **map);

//ft_free
size_t	ft_count(char **map);
void	ft_free_map(char **map);
void	ft_free(t_game *game);

#endif
