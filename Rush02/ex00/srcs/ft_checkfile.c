/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:59:48 by agilles           #+#    #+#             */
/*   Updated: 2023/07/23 19:02:56 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_02.h"

void	ft_ini_key(char *key[KEY_NB])
{
	int	i;

	i = 0;
	while (i < KEY_NB)
		key[i++] = NULL;
}

char	*ft_find_noprint(char *str)
{
	while (*str)
	{
		if (*str < ' ' || 127 <= *str)
			return (str);
		str++;
	}
	return (str);
}

int	ft_fill_key(char *str, int n, long nb, char *key[KEY_NB])
{
	int	key_count;
	int	key_index;
	int	i;

	i = 0;
	key_count = 0;
	key_index = -1;
	while (i < KEY_NB)
	{
		if (g_key[i] == nb)
			key_index = i;
		if (key[i] != NULL)
			key_count++;
		i++;
	}
	if (key_index == -1)
		return (key_count);
	if (key[key_index] == NULL)
	{
		key[key_index] = ft_strndup(str, n);
		key_count++;
	}
	return (key_count);
}

int	ft_checkfile(char *file, char *key[KEY_NB])
{
	long	nb;
	char	*current;
	int		key_count;

	while (*file)
	{
		nb = ft_strtol(file, &current);
		if (current == file)
			return (1);
		file = current;
		while (*file == ' ')
			file++;
		if (*file != ':')
			return (1);
		file++;
		while (*file == ' ')
			file++;
		current = ft_find_noprint(file);
		if (current == file || *current != '\n')
			return (1);
		key_count = ft_fill_key(file, current - file, nb, key);
		file = current + 1;
	}
	return (key_count != KEY_NB);
}
