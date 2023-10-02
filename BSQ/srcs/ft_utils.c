/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/24 21:47:30 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_coord	ft_set_coord(size_t line, size_t col)
{
	t_coord	coord;

	coord.line = line;
	coord.col = col;
	return (coord);
}

int	ft_solution_found(t_map *map)
{
	if (map->soluce.line == NO_INI || map->line <= map->soluce.line)
		return (0);
	if (map->soluce.col == NO_INI || map->col <= map->soluce.col)
		return (0);
	return (1);
}

size_t	ft_get_square_size(t_map *map)
{
	if (!ft_solution_found(map))
		return (0);
	return (map->map[map->soluce.line][map->soluce.col]);
}
