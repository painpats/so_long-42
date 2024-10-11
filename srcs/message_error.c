/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:27 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/13 17:28:58 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// error with .ber
void	merror_pber(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

// error with parsing
void	merror_pars(char *str, char **map)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(str, 2);
	ft_free_map(map);
	exit (EXIT_FAILURE);
}
