/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/15 18:46:15 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_column(int board[4][4])
{
	int	i;
	int	j;
	int	col;

	col = 0;
	while (col < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = i + 1;
			while (j < 4)
			{
				if (board[col][i] == board[col][j])
					return (1);
				j++;
			}
			i++;
		}
		col++;
	}
	return (0);
}
