/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/09 19:59:31 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	int	n;

	if (3 < argc)
	{
		n = atoi(argv[3]);
		printf("s1 = '%s', s2 = '%s', n = %d\n\\/\n", argv[1], argv[2], n);
		printf("strncmp = %d\n", strncmp(argv[1], argv[2], n));
		printf("ft_strncmp = %d\n", ft_strncmp(argv[1], argv[2], n));
	}
	else
		printf("required 's1' 's2' n\n");
}
*/
