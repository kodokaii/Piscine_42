/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:53:45 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 14:06:25 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHAR "ABABCBCB "

void	ft_putchar(char c);

void	print_pos(int x, int y, int x_comp, int y_comp)
{
	if (x_comp == 1 && y_comp == 1)
		ft_putchar(CHAR[0]);
	else if (x_comp == x && y_comp == 1)
		ft_putchar(CHAR[2]);
	else if (x_comp == 1 && y_comp == y)
		ft_putchar(CHAR[6]);
	else if (x_comp == x && y_comp == y)
		ft_putchar(CHAR[4]);
	else if (y_comp == 1)
		ft_putchar(CHAR[1]);
	else if (x_comp == x)
		ft_putchar(CHAR[3]);
	else if (y_comp == y)
		ft_putchar(CHAR[5]);
	else if (x_comp == 1)
		ft_putchar(CHAR[7]);
	else
		ft_putchar(CHAR[8]);
}

void	rush(int x, int y)
{
	int	x_comp;
	int	y_comp;

	if (x > 0 && y > 0)
	{
		y_comp = 1;
		while (y_comp <= y)
		{
			x_comp = 1;
			while (x_comp <= x)
			{
				print_pos(x, y, x_comp, y_comp);
				x_comp++;
			}
			ft_putchar('\n');
			y_comp++;
		}
	}
}
