/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexdump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/27 18:19:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

#define HEXA "0123456789abcdef"

void	ft_print_addr(unsigned int addr, int option)
{
	long	modulo;

	if (option == C_OPTION)
		modulo = 0x10000000;
	else
		modulo = 0x1000000;
	while (modulo)
	{
		ft_putoc(HEXA[addr / modulo]);
		addr %= modulo;
		modulo /= 16;
	}
}

void	ft_puthexa(t_oc c, t_oc d, int option, int size)
{
	ft_putoc(' ');
	if (0 < size)
	{
		ft_putoc(HEXA[c / 16]);
		ft_putoc(HEXA[c % 16]);
	}
	else
		write(1, "  ", 2);
	if (option == C_OPTION)
		ft_putoc(' ');
	if (0 < size - 1)
	{
		ft_putoc(HEXA[d / 16]);
		ft_putoc(HEXA[d % 16]);
	}
	else
		write(1, "  ", 2);
}

void	ft_print_hexa(t_oc buf[16], int size, int option)
{
	int	i;

	i = 0;
	if (size % 2 && option == NO_OPTION)
	{
		buf[size] = 0;
		size++;
	}
	while (i < 16)
	{
		if (i % 8 == 0 && option == C_OPTION)
			ft_putoc(' ');
		if (option == C_OPTION)
			ft_puthexa(buf[i], buf[i + 1], option, size - i);
		else
			ft_puthexa(buf[i + 1], buf[i], option, size - i);
		i += 2;
	}
	if (option == C_OPTION)
		write(1, "  ", 2);
}

void	ft_print_ascii(t_oc buf[16], int size)
{
	int	i;

	i = 0;
	ft_putoc('|');
	while (i < size)
	{
		if (buf[i] < ' ' || 127 <= buf[i])
			ft_putoc('.');
		else
			ft_putoc(buf[i]);
		i++;
	}
	ft_putoc('|');
}

void	ft_print_hexdump(t_hexbuf *hexbuf, int option)
{
	if (!hexbuf->addr || hexbuf->size < 16
		|| ft_memcmp(hexbuf->buf, hexbuf->old, hexbuf->size))
	{
		ft_print_addr(hexbuf->addr, option);
		if (hexbuf->size)
			ft_print_hexa(hexbuf->buf, hexbuf->size, option);
		if (hexbuf->size && option == C_OPTION)
			ft_print_ascii(hexbuf->buf, hexbuf->size);
		ft_putoc('\n');
		hexbuf->is_same = 0;
	}
	else if (!hexbuf->is_same)
	{
		write(1, "*\n", 2);
		hexbuf->is_same = 1;
	}
	ft_memcpy(hexbuf->old, hexbuf->buf, hexbuf->size);
	hexbuf->addr += hexbuf->size;
	hexbuf->size = 0;
}
