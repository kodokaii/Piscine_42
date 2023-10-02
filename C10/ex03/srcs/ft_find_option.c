/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 21:43:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_delete_arg(int *argc, char *argv[], int del)
{
	char	*buf;

	while (del < *argc)
	{
		buf = argv[del];
		argv[del] = argv[del + 1];
		argv[del + 1] = buf;
		del++;
	}
	(*argc)--;
}

int	ft_find_option(int *argc, char *argv[], char *option)
{
	int		i;

	i = 0;
	while (i < *argc && (argv[i][0] != option[0] || argv[i][1] != option[1]))
		i++;
	if (i < *argc)
	{
		ft_delete_arg(argc, argv, i);
		return (1);
	}
	return (0);
}
