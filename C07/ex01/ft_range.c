/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/16 00:02:01 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	long	range;

	range = max - min;
	if (range <= 0)
		return (NULL);
	tab = malloc(range * sizeof(int));
	if (!tab)
		return (NULL);
	while (range--)
		tab[range] = min + range;
	return (tab);
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
		range = max - min;
		tab = ft_range(min, max);
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
