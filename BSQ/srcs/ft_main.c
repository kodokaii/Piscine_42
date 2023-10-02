/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 00:11:03 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_bsq(char *map_path_name)
{
	t_map	map;

	if (ft_get_map(&map, map_path_name))
		return (ft_free(ERROR_GET_MAP, &map));
	if (ft_parse_map(&map))
		return (ft_free(ERROR_PARSE_MAP, &map));
	if (ft_find_soluce(&map))
		return (ft_free(ERROR_FIND_SOLUCE, &map));
	if (ft_print_soluce(&map))
		return (ft_free(ERROR_PRINT_SOLUCE, &map));
	return (ft_free(0, &map));
}

int	main(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i == 1 || i < argc)
	{
		if (i != 1)
			ft_putchar_fd(1, '\n');
		ft_bsq(argv[i]);
		i++;
	}
	return (0);
}
