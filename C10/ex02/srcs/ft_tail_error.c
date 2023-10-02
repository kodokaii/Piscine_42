/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 20:11:08 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_tail_arg_error(char *prog_name, char *option)
{
	ft_puterror(prog_name);
	ft_puterror(": option requires an argument -- '");
	ft_puterror(option);
	ft_puterror("'\nTry '");
	ft_puterror(prog_name);
	ft_puterror(" --help' for more information.\n");
	return (1);
}

int	ft_tail_num_error(char *c, char *prog_name, int error)
{
	ft_puterror(prog_name);
	ft_puterror(": invalid number of bytes: ‘");
	ft_puterror(c);
	ft_puterror("’");
	if (error == ERANGE)
		ft_puterror(": Value too large for defined data type");
	ft_puterror("\n");
	return (error);
}

void	ft_tail_open_error(char *file_path, char *prog_name)
{
	ft_puterror(prog_name);
	ft_puterror(": cannot open '");
	ft_puterror(file_path);
	ft_puterror("' for reading: ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
	errno = 0;
}

void	ft_tail_read_error(char	*file_path, char *prog_name)
{
	ft_puterror(prog_name);
	ft_puterror(": error reading '");
	ft_puterror(file_path);
	ft_puterror("': ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
	errno = 0;
}
