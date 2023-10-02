/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/15 19:15:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(int board[4][4])
{
	int	x;
	int	y;

	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			ft_putchar(board[x][y] + '0');
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
