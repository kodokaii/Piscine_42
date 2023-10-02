/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/15 17:37:22 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (to_find[0] == 0)
		return (str);
	while (*str)
	{
		i = 0;
		while (str[i] == to_find[i])
		{
			i++;
			if (to_find[i] == 0)
				return (str);
		}
		str++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (2 < argc)
	{
		printf("s1 = '%s', s2 = '%s'\n\\/\n", argv[1], argv[2]);
		printf("strstr = %s\n", strstr(argv[1], argv[2]));
		printf("ft_strstr = %s\n", ft_strstr(argv[1], argv[2]));
	}
	else
		printf("required 's1' 's2'\n");
}
*/
