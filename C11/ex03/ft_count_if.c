/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/19 18:42:36 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str < 'A' || ('Z' < *str && *str < 'a') || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (1 < argc)
	{
		argv++;
		argc--;
		printf("ft_count_if = %d\n", ft_count_if(argv, argc, &ft_str_is_alpha));
	}
	else
		printf("required 's1' ...\n");
}
*/
