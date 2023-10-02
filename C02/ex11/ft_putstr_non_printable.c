/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/10 13:03:03 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXA "0123456789abcdef"

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || 127 <= *str)
		{
			write(1, "\\", 1);
			write(1, &HEXA[(unsigned char)*str / 16], 1);
			write(1, &HEXA[(unsigned char)*str % 16], 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

/*
int	main (void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien");
	write(1, "\n", 1);
	ft_putstr_non_printable("Coucou tu vas bie\t\v\0n");
	write(1, "\n", 1);
	ft_putstr_non_printable("");
}
*/
