/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/23 19:02:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_02.h"

void	ft_putletters(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (str[0] != ' ' || str[-1] != ' ')
			write(1, str, 1);
		str++;
	}
}

void	ft_3digits_to_letters(char *key[KEY_NB], long nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb % 1000 / 100)
	{
		ft_putletters(key[nb % 1000 / 100]);
		write(1, " ", 1);
		ft_putletters(key[HUNDRED]);
		if (nb % 100 / 10 || nb % 10)
			write(1, " ", 1);
	}
	if (nb == 0)
		ft_putletters(key[0]);
	else if (20 < nb % 100)
	{
		if (nb % 100 / 10)
		{
			ft_putletters(key[18 + nb % 100 / 10]);
			if (nb % 10)
				write(1, "-", 1);
		}
		if (nb % 10)
			ft_putletters(key[nb % 10]);
	}
	else if (nb % 100)
		ft_putletters(key[nb % 100]);
}

void	ft_digits_to_letters(char *key[KEY_NB], long nb)
{
	long	modulo;
	int		unite;

	unite = KEY_NB;
	modulo = g_key[KEY_NB - 1];
	if (nb < 0)
		write(1, "negative ", 9);
	while (HUNDRED < --unite)
	{
		if (nb / modulo % 1000)
		{
			ft_3digits_to_letters(key, nb / modulo % 1000);
			write(1, " ", 1);
			ft_putletters(key[unite]);
			if (nb % modulo)
				write(1, " ", 1);
		}
		modulo /= 1000;
	}
	if (nb % 1000 || nb == 0)
		ft_3digits_to_letters(key, nb);
}

int	main(int argc, char *argv[])
{
	char		*key[KEY_NB];
	char		*file;
	long		nb;
	int			error;

	ft_ini_key(key);
	error = ft_pick_arg(--argc, ++argv, &file, &nb);
	if (error)
		return (ft_end(error, file, key));
	if (ft_checkfile(file, key))
		return (ft_end(ERROR_DICT, file, key));
	if (nb < -NB_MAX || NB_MAX < nb)
		return (ft_end(ERROR_LIMIT, file, key));
	ft_digits_to_letters(key, nb);
	write(1, "\n", 1);
	return (ft_end(0, file, key));
}
