/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/16 19:53:33 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_board(int board[4][4]);
int		error(void);
int		pick_arg(int arg[16], char *str);
int		find_solution(int board[4][4], int arg[16]);

int	main(int argc, char *argv[])
{
	int	arg[16];
	int	board[4][4];

	if (argc != 2)
		return (error());
	if (pick_arg(arg, argv[1]))
		return (error());
	if (find_solution(board, arg))
		return (error());
	print_board(board);
}
