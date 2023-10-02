/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:53:45 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/08 14:15:48 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_pos(int x, int y, int x_comp, int y_comp)
{
	if (x_comp == 1 && y_comp == 1)
		ft_putchar('/');
	else if (x_comp == x && y_comp == 1)
		ft_putchar('\\');
	else if (x_comp == 1 && y_comp == y)
		ft_putchar('\\');
	else if (x_comp == x && y_comp == y)
		ft_putchar('/');
	else if (y_comp == 1)
		ft_putchar('*');
	else if (x_comp == x)
		ft_putchar('*');
	else if (y_comp == y)
		ft_putchar('*');
	else if (x_comp == 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
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
