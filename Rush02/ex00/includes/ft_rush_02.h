/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_02.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/23 20:22:59 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_02_H
# define FT_RUSH_02_H

# define KEY_NB 32
# define NB_MAX 999999999999
# define HUNDRED 28
# define DICT_NAME "numbers.dict"
# define ERROR_DICT 1
# define ERROR_LIMIT 2
# define ERROR_NB 3
# define ERROR_ARG 4

# include "ft_file.h"
# include "ft_strndup.h"
# include <stdio.h>

static const long	g_key[KEY_NB] = {\
		0,			\
		1,			\
		2,			\
		3,			\
		4,			\
		5,			\
		6,			\
		7,			\
		8,			\
		9,			\
		10,			\
		11,			\
		12,			\
		13,			\
		14,			\
		15,			\
		16,			\
		17,			\
		18,			\
		19,			\
		20,			\
		30,			\
		40,			\
		50,			\
		60,			\
		70,			\
		80,			\
		90,			\
		100,		\
		1000,		\
		1000000,	\
		1000000000};

long	ft_strtol(char *str, char **end);
int		ft_checkfile(char *file, char *key[KEY_NB]);
void	ft_ini_key(char *key[KEY_NB]);
int		ft_end(int error, char *file, char *key[KEY_NB]);
int		ft_pick_arg(int argc, char *argv[], char **file, long *nb);

#endif
