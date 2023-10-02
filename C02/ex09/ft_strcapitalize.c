/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 22:22:53 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		len;
	int		state;

	len = 0;
	state = 1;
	while (str[len])
	{
		if ('a' <= str[len] && str[len] <= 'z')
		{
			if (state == 1)
				str[len] -= 'a' - 'A';
			state = 0;
		}
		else if (('A' <= str[len] && str[len] <= 'Z')
			|| ('0' <= str[len] && str[len] <= '9'))
		{
			if (state == 0 && 'A' <= str[len] && str[len] <= 'Z')
				str[len] += 'a' - 'A';
			state = 0;
		}
		else
			state = 1;
		len++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("str = %s\n", str);
	printf("capitalizeStr = %s\n", ft_strcapitalize(str));
}
*/
