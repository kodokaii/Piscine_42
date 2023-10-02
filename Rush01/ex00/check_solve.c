/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/15 19:14:34 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	get_line(int line[4], int board[4][4], int y)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		line[x] = board[x][y];
		x++;
	}
}

static int	check_view_left(int arg_left, int line[4])
{
	int	max_value;
	int	see;
	int	i;

	i = 1;
	see = 1;
	max_value = line[0];
	while (i < 4)
	{
		if (max_value < line[i])
		{
			max_value = line[i];
			see++;
		}
		i++;
	}
	if (see != arg_left)
		return (1);
	return (0);
}

static int	check_view_right(int arg_right, int line[4])
{
	int	max_value;
	int	see;
	int	i;

	i = 2;
	see = 1;
	max_value = line[3];
	while (0 <= i)
	{
		if (max_value < line[i])
		{
			max_value = line[i];
			see++;
		}
		i--;
	}
	if (see != arg_right)
		return (1);
	return (0);
}

int	check_solve(int board[4][4], int arg[16])
{
	int	current_line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check_view_left(arg[i], board[i]))
			return (1);
		if (check_view_right(arg[i + 4], board[i]))
			return (1);
		get_line(current_line, board, i);
		if (check_view_left(arg[i + 8], current_line))
			return (1);
		if (check_view_right(arg[i + 12], current_line))
			return (1);
		i++;
	}
	return (0);
}
