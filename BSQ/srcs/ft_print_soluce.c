/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_soluce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 00:36:20 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_is_in_square(t_map *map, size_t line, size_t col)
{
	size_t	square_size;

	square_size = ft_get_square_size(map);
	if (!square_size)
		return (0);
	square_size--;
	if ((map->soluce.line - square_size <= line && line <= map->soluce.line)
		&& (map->soluce.col - square_size <= col && col <= map->soluce.col))
		return (1);
	return (0);
}

int	ft_print_soluce(t_map *map)
{
	size_t	line;
	size_t	col;

	line = 0;
	while (line < map->line)
	{
		col = 0;
		while (col < map->col)
		{
			if (ft_is_in_square(map, line, col))
				ft_putchar_fd(1, map->fill);
			else if (map->map[line][col] == BLOCK)
				ft_putchar_fd(1, map->block);
			else
				ft_putchar_fd(1, map->empty);
			col++;
		}
		ft_putchar_fd(1, '\n');
		line++;
	}
	return (0);
}
