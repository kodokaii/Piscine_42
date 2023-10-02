/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/26 12:39:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail_banner(char *file_path)
{
	static int	count_read = 0;

	if (count_read)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	while (*file_path)
		write(1, file_path++, 1);
	write(1, " <==\n", 5);
	count_read += 1;
}

void	ft_tail_c(char *file, size_t file_size, size_t oc)
{
	if (file_size <= oc)
		write(1, file, file_size);
	else
		write(1, file + file_size - oc, oc);
}

int	ft_tail_line(char *file, size_t file_size, \
				size_t start_line, size_t goal_line)
{
	size_t	end;
	size_t	current_line;

	end = 0;
	current_line = 1;
	while (file[end] != '\n' && end < file_size)
		end++;
	end++;
	if (end < file_size)
		current_line = ft_tail_line(file + end, file_size - end \
				, start_line + 1, goal_line);
	if (current_line == goal_line
		|| (start_line == 0 && current_line < goal_line))
		write(1, file, file_size);
	return (current_line + 1);
}

int	ft_tail(int files_count, char *files_path[], char *prog_name, size_t *oc)
{
	size_t	file_size;
	char	*file;
	int		error;
	int		i;

	i = 0;
	while (!i || i < files_count)
	{
		error = ft_open_file(files_path[i], &file, &file_size);
		if (1 < files_count && error != OPEN_ERROR)
			ft_tail_banner(files_path[i]);
		if (error == OPEN_ERROR)
			ft_tail_open_error(files_path[i], prog_name);
		else if (error == READ_ERROR)
			ft_tail_read_error(files_path[i], prog_name);
		else if (oc)
			ft_tail_c(file, file_size, *oc);
		else
			ft_tail_line(file, file_size, 0, 10);
		if (file)
			free(file);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	size_t	oc;
	char	*c;
	char	*end;

	argc--;
	argv++;
	if (ft_pick_c(&argc, argv, &c))
		return (ft_tail(argc, argv, argv[-1], NULL));
	else
	{
		if (c)
		{
			oc = ft_strtoull(c, &end);
			if (end[0])
				return (ft_tail_num_error(c, argv[-1], 1));
			if (errno == ERANGE)
				return (ft_tail_num_error(c, argv[-1], ERANGE));
			if (oc && ft_tail(argc, argv, argv[-1], &oc))
				return (1);
		}
		else
			return (ft_tail_arg_error(argv[-1], "c"));
		return (0);
	}
}
