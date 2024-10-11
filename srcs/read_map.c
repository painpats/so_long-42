/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:53 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/14 16:22:32 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// get the number of lines
static int	ft_len_map(char *pber)
{
	char	*tmp;
	int		len;
	int		fd;

	tmp = NULL;
	len = 0;
	fd = open(pber, O_RDONLY);
	tmp = get_next_line(fd);
	len++;
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
		len++;
	}
	if (tmp)
		free(tmp);
	close(fd);
	return (len - 1);
}

// open and read the .ber
char	**ft_read_map(char *pber)
{
	char	**map;
	char	*tmp;
	int		len;
	int		fd;
	int		i;

	len = ft_len_map(pber);
	map = malloc(sizeof(char *) * (len + 1));
	map[len] = NULL;
	fd = open(pber, O_RDONLY);
	i = 0;
	while (i < len)
	{
		tmp = get_next_line(fd);
		map[i] = ft_substr(tmp, 0, (ft_strlen(tmp) - 1));
		free(tmp);
		i++;
	}
	close(fd);
	if (!map[0])
		merror_pars("The file is empty\n", map);
	if (map[0][0] == '\0')
		merror_pars("The file is empty\n", map);
	return (map);
}

// print the mouvement of the player
int	ft_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->step += 1;
		ft_printf("Rollin' : %d\n", game->step);
		return (1);
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->bag += 1;
		game->step += 1;
		ft_printf("Rollin' : %d\n", game->step);
		return (1);
	}
	if (game->map[y][x] == 'E' && (game->bag == game->sym.c))
	{
		game->map[y][x] = 'P';
		game->step += 1;
		ft_printf("Rollin' : %d\n", game->step);
		ft_quit_game(game);
		return (1);
	}
	return (-1);
}
