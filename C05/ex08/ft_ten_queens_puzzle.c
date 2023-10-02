/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/13 13:07:15 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define S 10

void	print_board(int board[S])
{
	char	c;
	int		i;

	i = 0;
	while (i < S)
	{
		c = board[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	find_comb(int board[S], int x)
{
	int	cursor;

	cursor = -1;
	while (cursor != x)
	{
		if (board[x] < S - 1)
			board[x]++;
		else if (0 < x)
		{
			board[x] = -1;
			return (find_comb(board, x - 1));
		}
		else
			return (0);
		cursor = 0;
		while (cursor < x
			&& board[cursor] - (x - cursor) != board[x]
			&& board[cursor] + (x - cursor) != board[x]
			&& board[cursor] != board[x])
			cursor++;
	}
	if (x < S - 1)
		return (find_comb(board, x + 1));
	print_board(board);
	return (find_comb(board, x) + 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	x;
	int	board[S];

	x = 0;
	while (x < S)
		board[x++] = -1;
	return (find_comb(board, 0));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("nombre de solution = %d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
