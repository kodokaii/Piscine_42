/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/10 13:29:42 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define HEXA "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(void *addr)
{
	unsigned long long	modulo;
	unsigned long long	cpy_addr;	

	modulo = 0x1000000000000000;
	cpy_addr = (unsigned long long)addr;
	while (modulo)
	{
		ft_putchar(HEXA[cpy_addr / modulo]);
		cpy_addr %= modulo;
		modulo /= 16;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_hexa(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_putchar(HEXA[addr[i] / 16]);
			ft_putchar(HEXA[addr[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
}

void	print_ascii(char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 16)
	{
		if (addr[i] < ' ' || 127 <= addr[i])
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size)
	{
		print_addr(addr);
		print_hexa(addr, size);
		print_ascii(addr, size);
		if (16 < size)
			ft_print_memory(addr + 16, size - 16);
	}
	return (addr);
}

/*
int		main(void)
{
	char str[] = "Boule et Bill \n\t\vobjectif 100%\n\tallez plus que 11 exo !\n";
	ft_print_memory(str, 57);
}
*/
