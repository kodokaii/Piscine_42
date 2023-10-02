/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 02:11:36 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	if (!src)
		return (NULL);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

int	ft_free_buf(int error, char *buf)
{
	if (buf)
		free(buf);
	return (error);
}

int	ft_save_file(int file, char **file_save, size_t *file_size)
{
	ssize_t	oc_read;	
	char	*buf;

	buf = malloc(BUF_SIZE);
	if (!buf)
		return (ft_free_buf(MALLOC_ERROR, buf));
	oc_read = read(file, buf, BUF_SIZE);
	if (oc_read < 0)
		return (ft_free_buf(READ_ERROR, buf));
	if (oc_read == 0)
	{
		*file_save = malloc(*file_size + 1) + *file_size;
		if (!(*file_save - *file_size))
			return (ft_free_buf(MALLOC_ERROR, buf));
		**file_save = 0;
	}
	else
	{
		*file_size += oc_read;
		if (ft_save_file(file, file_save, file_size))
			return (ft_free_buf(MALLOC_ERROR, buf));
	}
	*file_save = ft_memcpy(*file_save - oc_read, buf, oc_read);
	return (ft_free_buf(0, buf));
}

int	ft_open_file(char *file_path, char **file_save, size_t *file_size)
{
	size_t	file_size_buf;
	int		file;
	int		error;

	file = 0;
	file_size_buf = 0;
	*file_save = NULL;
	if (file_path)
		file = open(file_path, O_RDONLY);
	if (file < 0)
		return (OPEN_ERROR);
	error = ft_save_file(file, file_save, &file_size_buf);
	if (file)
		close (file);
	if (file_size)
		*file_size = file_size_buf;
	return (error);
}
