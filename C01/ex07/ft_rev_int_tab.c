/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 11:16:55 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	buf;

	if (1 < size)
	{
		buf = tab[0];
		tab[0] = tab[size - 1];
		tab[size - 1] = buf;
		ft_rev_int_tab(++tab, size - 2);
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	size;
	int	tab[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	size = 10;
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
		, tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
		tab[6], tab[7], tab[8], tab[9]);
	printf("ft_rev_int_tab(tab, size);\n");
	ft_rev_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n"
		, tab[0], tab[1], tab[2], tab[3], tab[4], tab[5],
		tab[6], tab[7], tab[8], tab[9]);
	return (0);
}
*/
