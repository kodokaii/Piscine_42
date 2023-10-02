/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/16 00:06:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	*range = NULL;
	size = max - min;
	if (size <= 0)
		return (0);
	*range = malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	min;
	int	max;
	int	*tab;
	int	range;
	int	i;

	if (2 < argc)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		range = ft_ultimate_range(&tab, min, max);
		printf("range = %d\n", range);
		if (tab && 0 < range)
		{
			i = 0;
			while (i < range)
			{
				printf("%d", tab[i++]);
				if (i < range)
					printf(", ");
			}
			printf("\n");
		}
		else
			printf("NULL\n");
	}
	else
		printf("required 'min' 'max'\n");
	return (0);
}
*/
