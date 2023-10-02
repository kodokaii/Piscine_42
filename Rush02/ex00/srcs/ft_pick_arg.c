/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 12:41:53 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_02.h"

int	ft_end(int error, char *file, char *key[KEY_NB])
{
	int	i;

	i = 0;
	if (file)
		free(file);
	while (error != ERROR_NB && i < KEY_NB)
	{
		if (key[i])
			free(key[i]);
		i++;
	}
	if (error == ERROR_DICT)
		write(2, "Dict Error\n", 11);
	else if (error == ERROR_LIMIT)
		write(2, "Number is too big\n", 18);
	else if (error == ERROR_NB)
		write(2, "The format number is invalid\n", 29);
	return (error);
}

int	ft_pick_arg(int argc, char *argv[], char **file, long *nb)
{
	char	*current;

	if (2 < argc)
		return (ERROR_ARG);
	if (argc == 2)
	{
		*file = ft_open_file(argv[0]);
		*nb = ft_strtol(argv[1], &current);
		if (current == argv[1] || *current)
			return (ERROR_NB);
	}
	else
	{
		if (argc == 0)
			argv[0] = ft_open_file(NULL);
		*file = ft_open_file(DICT_NAME);
		*nb = ft_strtol(argv[0], &current);
		if (current == argv[0] || *current)
			return (ERROR_NB);
		if (argc == 0 && argv[0])
			free(argv[0]);
	}
	if (!(*file) || !argv[0])
		return (ERROR_DICT);
	return (0);
}
