/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 01:52:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	if (!src)
		return (NULL);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

void	*ft_realloc(void *ptr, size_t current_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (current_size < new_size)
		ft_memcpy(new_ptr, ptr, current_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	if (current_size)
		free(ptr);
	return (new_ptr);
}

char	*ft_save_file(int file)
{
	size_t	file_size;
	ssize_t	oc_read;	
	char	buf[BUF_SIZE];
	char	*file_save;

	file_size = 0;
	oc_read = 1;
	file_save = NULL;
	while (oc_read != 0)
	{
		oc_read = read(file, buf, BUF_SIZE);
		if (oc_read < 0)
			return (NULL);
		file_save = ft_realloc(file_save, file_size, file_size + oc_read + 1);
		if (!file_save)
			return (NULL);
		ft_memcpy(file_save + file_size, buf, oc_read);
		file_size += oc_read;
		file_save[file_size] = 0;
	}
	return (file_save);
}

char	*ft_open_file(char *path_file)
{
	int		file;
	char	*cpy_file;

	file = 0;
	if (path_file)
		file = open(path_file, O_RDONLY);
	if (file < 0)
		return (NULL);
	cpy_file = ft_save_file(file);
	if (file)
		close (file);
	return (cpy_file);
}
