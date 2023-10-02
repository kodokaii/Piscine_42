/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 23:16:42 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF 2048

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

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

void	ft_cat_error(char	*file_path, char *prog_name)
{
	ft_puterror(prog_name);
	ft_puterror(": ");
	ft_puterror(file_path);
	ft_puterror(": ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
}

int	ft_cat(int files_count, char **files_path, char *prog_name)
{
	int	i;

	i = 0;
	while (!i || i < files_count)
	{
		if (ft_display_file(files_path[i]))
			ft_cat_error(files_path[i], prog_name);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (ft_cat(argc - 1, argv + 1, argv[0]))
		return (1);
	return (0);
}
