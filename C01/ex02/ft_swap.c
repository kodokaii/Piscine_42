/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 10:34:02 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	buf;

	buf = *a;
	*a = *b;
	*b = buf;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int b;

	a = 0;
	b = 42;
	printf("a = %d et b = %d\n", a, b);
	printf("ft_swap(&a, &b);\n");
	ft_swap(&a, &b);
	printf("a = %d et b = %d\n", a, b);
}
*/
