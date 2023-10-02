/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/06 12:09:40 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	kdo_display_combn(char *digits, int n)
{
	int	i;

	i = -n;
	while (i <= 0)
		ft_putchar(digits[i++]);
	if (digits[-n] != '9' - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	kdo_recursive_combn(char *digits, int n, int deep)
{
	while (digits[0] <= '9' - deep)
	{
		if (deep)
		{
			digits[1] = digits[0] + 1;
			kdo_recursive_combn(digits + 1, n, deep - 1);
		}
		else
			kdo_display_combn(digits, n);
		digits[0]++;
	}
}

void	ft_print_combn(int n)
{
	char	digits[10];

	digits[0] = '0';
	if (n)
		kdo_recursive_combn(digits, n - 1, n - 1);
}

/*
int	main(int argc, char *argv[])
{
	(void) argc;
	ft_print_combn(argv[1][0] - '0');
	return (0);
}
*/
