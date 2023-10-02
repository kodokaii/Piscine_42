/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/11 17:48:38 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	index;

	if (1 < argc)
	{
		index = atoi(argv[1]);
		printf("ft_fibonacci(%d) = %d\n", index, ft_fibonacci(index));
	}
	else
		printf("required 'index'\n");
}
*/
