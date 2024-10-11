/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:01 by cbourre           #+#    #+#             */
/*   Updated: 2023/02/14 16:50:26 by cbourre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if it's the right extension
void	ext_checker(char *file_n, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file_n) - 1;
	j = ft_strlen(ext) - 1;
	if (i <= j)
		merror_pber("Something's wrong with the extension\n");
	while (i >= 0 && j >= 0)
	{
		if (file_n[i] == ext[j])
		{
			i--;
			j--;
		}
		else if (file_n[i] != ext[j])
			merror_pber("Something's wrong with the extension\n");
	}
	if (file_n[i] == '/')
		merror_pber("Something's wrong with the extension\n");
}
