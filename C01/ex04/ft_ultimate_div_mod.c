/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 10:48:17 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int b;

	a = 85;
	b = 2;
	printf("a = %d , b = %d\n", a, b);
	printf("ft_ultimate_div_mod(&a, &b);\n");
	ft_ultimate_div_mod(&a, &b);
	printf("a = %d , b = %d\n", a, b);
}
*/
