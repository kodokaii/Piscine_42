/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/24 22:02:46 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_get_map(t_map *new_map, char *map_path_name)
{
	new_map->map = NULL;
	new_map->empty = 0;
	new_map->block = 0;
	new_map->fill = 0;
	new_map->line = 0;
	new_map->col = 0;
	new_map->soluce = ft_set_coord(NO_INI, NO_INI);
	return (ft_open_file(map_path_name, &new_map->file, NULL));
}
