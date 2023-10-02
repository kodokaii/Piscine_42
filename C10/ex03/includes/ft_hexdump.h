/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 16:36:00 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <stdio.h>
# include <string.h>

# define NO_OPTION 0
# define C_OPTION 1

typedef unsigned char	t_oc;

typedef struct s_hexbuf
{
	t_oc	buf[16];
	t_oc	old[16];
	int		size;
	int		addr;
	int		is_same;
}	t_hexbuf;

void	ft_hexdump_error(char *file_path, char *prog_name);
int		ft_find_option(int *argc, char *argv[], char *option);
void	ft_print_hexdump(t_hexbuf *hexbuf, int option);
void	ft_print_addr(unsigned int addr, int option);
void	ft_putoc(t_oc c);
void	*ft_memcpy(void *dest, void *src, size_t n);
int		ft_memcmp(void *s1, void *s2, int n);

#endif
