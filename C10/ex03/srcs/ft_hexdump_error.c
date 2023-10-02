/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 16:35:24 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_hexdump_error(char *file_path, char *prog_name)
{
	ft_puterror(basename(prog_name));
	ft_puterror(": ");
	ft_puterror(file_path);
	ft_puterror(": ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
	errno = 0;
}
