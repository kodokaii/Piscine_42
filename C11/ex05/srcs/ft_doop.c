/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 00:14:10 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int	ft_op_error(int nb1, int nb2)
{
	(void)nb1;
	(void)nb2;
	write(2, "0\n", 2);
	return (1);
}

int	ft_pick_op(char *op)
{
	if (op[1] != 0)
		return (5);
	if (op[0] == '+')
		return (0);
	if (op[0] == '-')
		return (1);
	if (op[0] == '*')
		return (2);
	if (op[0] == '/')
		return (3);
	if (op[0] == '%')
		return (4);
	return (5);
}

int	ft_doop(char *nb1, char *op, char *nb2)
{
	int	(*f[6])(int, int);

	f[0] = &ft_add;
	f[1] = &ft_sub;
	f[2] = &ft_mul;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	f[5] = &ft_op_error;
	return (f[ft_pick_op(op)](ft_atoi(nb1), ft_atoi(nb2)));
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		return (ft_doop(argv[1], argv[2], argv[3]));
	return (1);
}
