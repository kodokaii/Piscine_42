/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 18:40:35 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF 32768

int	ft_display_file(char *name)
{
	int		file;
	int		oc_read;
	char	buf[BUF];

	file = 0;
	oc_read = 1;
	if (name)
		file = open(name, O_RDONLY);
	if (file < 0)
		return (1);
	while (oc_read)
	{
		oc_read = read(file, buf, BUF);
		if (oc_read < 0)
			return (1);
		write(1, buf, oc_read);
	}
	close(file);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (2 < argc)
		write(2, "Too many arguments.\n", 20);
	else if (ft_display_file(argv[1]))
		write(2, "Cannot read file.\n", 18);
	else
		return (0);
	return (1);
}
