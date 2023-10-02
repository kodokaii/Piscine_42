/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 18:37:22 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (2 < argc)
	{
		printf("s1 = '%s', s2 = '%s'\n\\/\n", argv[1], argv[1]);
		printf("strcmp = %d\n", strcmp(argv[1], argv[2]));
		printf("ft_strcmp = %d\n", ft_strcmp(argv[1], argv[2]));
	}
	else
		printf("required 's1' 's2'\n");
}
*/
