/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 17:27:55 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_get_nb(char *start, char *end, size_t *nb)
{
	*nb = 0;
	while ('0' <= *start && *start <= '9')
	{
		*nb *= 10;
		*nb += *start - '0';
		if (++start == end)
			return (0);
	}
	return (1);
}

int	ft_parse_first_line(t_map *map, char **file)
{
	char	*end;

	end = *file;
	while (*end != 0 && *end != '\n')
		end++;
	if (!*end || end - *file < 4)
		return (1);
	if (!ft_isprint(end[-1]) || !ft_isprint(end[-2]) || !ft_isprint(end[-3]))
		return (1);
	if (end[-1] == end[-2] || end[-2] == end[-3] || end[-1] == end[-3])
		return (1);
	if (ft_get_nb(*file, end - 3, &map->line))
		return (1);
	map->fill = end[-1];
	map->block = end[-2];
	map->empty = end[-3];
	*file = end + 1;
	return (0);
}

int	ft_malloc_map(t_map *map)
{
	size_t	line;

	line = 0;
	map->map = malloc(map->line * sizeof(size_t));
	if (!map->map)
		return (1);
	while (line < map->line)
	{
		map->map[line] = malloc(map->col * sizeof(size_t));
		if (!map->map[line])
			return (1);
		line++;
	}
	return (0);
}

int	ft_fill_map(t_map *map, char *file)
{
	size_t	line;
	size_t	col;

	line = 0;
	if (ft_malloc_map(map))
		return (1);
	while (line < map->line)
	{
		col = 0;
		while (col < map->col)
		{
			if (file[col] == map->empty)
				map->map[line][col] = EMPTY;
			else
				map->map[line][col] = BLOCK;
			col++;
		}
		file += col + 1;
		line++;
	}
	return (0);
}

int	ft_parse_map(t_map *map)
{
	size_t	col;
	size_t	line;
	char	*file;

	file = map->file;
	if (ft_parse_first_line(map, &file))
		return (1);
	line = 0;
	while (line < map->line && *file)
	{
		col = 0;
		while (file[col] == map->block || file[col] == map->empty)
			col++;
		if (!map->col)
			map->col = col;
		if (map->col != col || file[col] != '\n')
			return (1);
		file += col + 1;
		line++;
	}
	if (map->col && map->line && line == map->line)
		return (ft_fill_map(map, file - ((map->col + 1) * map->line)));
	return (1);
}
