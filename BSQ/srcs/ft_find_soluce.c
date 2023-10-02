/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_soluce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/27 12:07:57 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_fill_corner_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->col)
	{
		if (map->map[0][i] == EMPTY)
		{
			map->map[0][i] = 1;
			if (!ft_solution_found(map))
				map->soluce = ft_set_coord(0, i);
		}
		i++;
	}
	i = 0;
	while (i < map->line)
	{
		if (map->map[i][0] == EMPTY)
		{
			map->map[i][0] = 1;
			if (!ft_solution_found(map))
				map->soluce = ft_set_coord(i, 0);
		}
		i++;
	}
}

size_t	ft_fill_case(t_map *map, size_t line, size_t col)
{
	size_t	square;

	if (map->map[line][col] == BLOCK)
		return (BLOCK);
	square = map->map[line - 1][col];
	if (map->map[line - 1][col - 1] < square)
		square = map->map[line - 1][col - 1];
	if (map->map[line][col - 1] < square)
		square = map->map[line][col - 1];
	return (square + 1);
}

int	ft_find_soluce(t_map *map)
{
	size_t	line;
	size_t	col;

	line = 1;
	ft_fill_corner_map(map);
	while (line < map->line)
	{
		col = 1;
		while (col < map->col)
		{
			map->map[line][col] = ft_fill_case(map, line, col);
			if (ft_get_square_size(map) < map->map[line][col])
				map->soluce = ft_set_coord(line, col);
			col++;
		}
		line++;
	}
	return (0);
}
