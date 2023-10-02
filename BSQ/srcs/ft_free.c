/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 02:07:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_free(int error, t_map *map)
{
	size_t	i;

	i = 0;
	if (map->file)
		free(map->file);
	if (map->map)
	{
		while (i < map->line && map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (error)
		write(2, "map error\n", 10);
	return (error);
}
