/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 11:19:57 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	before;
	int	after;

	before = 0;
	after = 0;
	while (before + 1 + after < size)
	{
		if (tab[before + 1] <= tab[0])
			before++;
		else
		{
			ft_swap(&tab[before + 1], &tab[size - after - 1]);
			after++;
		}
	}
	ft_swap(&tab[0], &tab[before]);
	if (1 < before)
		ft_sort_int_tab(tab, before);
	if (1 < after)
		ft_sort_int_tab(tab + size - after, after);
}

/*
#include <stdio.h>

int	main(void)
{
	int	size;
	int	tab[] = {3,8,6,7,5,4,9,2,1,0};

	size = 10;
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
		, tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
		tab[6], tab[7], tab[8], tab[9]);
	printf("ft_sort_int_tab(tab, size);\n");
	ft_sort_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
		, tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
		tab[6], tab[7], tab[8], tab[9]);
	return (0);
}
*/
