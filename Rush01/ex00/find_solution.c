/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/15 19:06:22 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_column(int board[4][4]);
int		check_solve(int board[4][4], int arg[16]);
void	error(void);

static int const	g_line_comb[24][4] = {
{1, 2, 3, 4},
{1, 2, 4, 3},
{1, 3, 2, 4},
{1, 3, 4, 2},
{1, 4, 2, 3},
{1, 4, 3, 2},
{2, 1, 3, 4},
{2, 1, 4, 3},
{2, 3, 1, 4},
{2, 3, 4, 1},
{2, 4, 1, 3},
{2, 4, 3, 1},
{3, 1, 2, 4},
{3, 1, 4, 2},
{3, 2, 1, 4},
{3, 2, 4, 1},
{3, 4, 1, 2},
{3, 4, 2, 1},
{4, 1, 2, 3},
{4, 1, 3, 2},
{4, 2, 1, 3},
{4, 2, 3, 1},
{4, 3, 1, 2},
{4, 3, 2, 1}
};

static void	fill_board(int board[4][4], int current_solution[4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			board[y][x] = g_line_comb[current_solution[x]][y];
			y++;
		}
		x++;
	}
}

static int	next_solution(int current_solution[4])
{
	int	i;

	i = 0;
	while (i < 4 && 23 <= current_solution[i])
	{
		current_solution[i] = 0;
		i++;
	}
	if (i < 4)
	{
		current_solution[i]++;
		return (1);
	}
	else
		return (0);
}

int	find_solution(int board[4][4], int arg[16])
{
	int	current_solution[4];	
	int	i;

	i = 0;
	while (i < 4)
		current_solution[i++] = 0;
	while (next_solution(current_solution))
	{
		fill_board(board, current_solution);
		if (!check_column(board) && !check_solve(board, arg))
			return (0);
	}
	return (1);
}
