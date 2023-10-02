/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 13:41:36 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_hexdump_read(char *file_path, t_hexbuf *hexbuf, int option)
{
	int	oc_read;
	int	file;

	file = 0;
	oc_read = 1;
	if (file_path)
		file = open(file_path, O_RDONLY);
	if (file < 0)
		return (1);
	while (oc_read)
	{
		oc_read = read(file, hexbuf->buf + hexbuf->size, 16 - hexbuf->size);
		if (oc_read < 0)
			return (1);
		hexbuf->size += oc_read;
		if (hexbuf->size == 16)
			ft_print_hexdump(hexbuf, option);
	}
	if (file)
		close(file);
	return (0);
}

int	ft_hexdump(int files_count, char *files_path[], char *prog_name, int option)
{
	t_hexbuf	hexbuf;
	int			i;

	i = 0;
	hexbuf.size = 0;
	hexbuf.addr = 0;
	while (!i || i < files_count)
	{
		if (ft_hexdump_read(files_path[i], &hexbuf, option))
			ft_hexdump_error(files_path[i], prog_name);
		i++;
	}
	if (hexbuf.size)
		ft_print_hexdump(&hexbuf, option);
	if (hexbuf.addr)
	{
		ft_print_addr(hexbuf.addr, option);
		ft_putoc('\n');
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	option;

	argc--;
	argv++;
	option = NO_OPTION;
	if (ft_find_option(&argc, argv, "-C"))
		option = C_OPTION;
	return (ft_hexdump(argc, argv, argv[-1], option));
}
