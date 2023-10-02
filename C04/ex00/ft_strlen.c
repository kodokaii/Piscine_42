/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/10 19:10:21 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
#include <stdio.h>
#include <string.h>

int    main(int argc, char **argv)
{
	if (1 < argc)
	{
		printf("strlen = %lu\n", strlen(argv[1]));
		printf("ft_strlen = %d\n", ft_strlen(argv[1]));
	}
	else
		printf("required 's1'\n");
	return (0);
}
*/
