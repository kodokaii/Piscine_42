/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/24 17:16:32 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include "ft_file.h"
# include <stdio.h>

size_t	ft_strtoull(char *str, char **end);
int		ft_pick_c(int *argc, char *argv[], char **c);
int		ft_tail_arg_error(char *prog_name, char *option);
int		ft_tail_num_error(char *c, char *prog_name, int error);
void	ft_tail_read_error(char *file_path, char *prog_name);
void	ft_tail_open_error(char *file_path, char *prog_name);

#endif
