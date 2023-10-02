/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 12:50:02 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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

int	ft_pick_c(int *argc, char *argv[], char **c)
{
	int		i;

	i = 0;
	while (i < *argc && (argv[i][0] != '-' || argv[i][1] != 'c'))
		i++;
	if (i < *argc)
	{
		if (argv[i][2])
			*c = argv[i] + 2;
		else
		{
			*c = argv[i + 1];
			ft_delete_arg(argc, argv, i + 1);
		}
		ft_delete_arg(argc, argv, i);
		return (0);
	}
	return (1);
}
