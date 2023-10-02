/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/19 21:59:17 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H

# include <unistd.h>

int		ft_doop(char *nb1, char *op, char *nb2);
int		ft_atoi(char *str);
int		ft_add(int nb1, int nb2);
int		ft_sub(int nb1, int nb2);
int		ft_mul(int nb1, int nb2);
int		ft_div(int nb1, int nb2);
int		ft_mod(int nb1, int nb2);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
