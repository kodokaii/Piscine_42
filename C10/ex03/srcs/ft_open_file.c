/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/20 20:45:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

#define NB_ALLOC_MAX 10

void	*ft_memcpy(char *dest, char *src, unsigned int n)
{
	if (!src || !dest)
		return (NULL);
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	*ft_save_file(int file, t_lld *file_size)
{
	ssize_t	oc_read;	
	char	buf[BUF];
	char	*file_save;

	oc_read = read(file, buf, BUF);
	if (oc_read < 0)
		return (NULL);
	if (oc_read == 0)
	{
		file_save = malloc(*file_size * sizeof(char));
		if (file_save == NULL)
			return (NULL);
		return (file_save + *file_size);
	}
	*file_size += oc_read;
	file_save = ft_save_file(file, file_size);
	if (file_save == NULL)
		return (NULL);
	return (ft_memcpy(file_save - oc_read, buf, oc_read));
}

int	ft_open_file(char *path_file, char **cpy_file, t_lld *file_size)
{
	int	file;
	int	nb_alloc;

	file = 0;
	*file_size = 0;
	nb_alloc = 0;
	*cpy_file = NULL;
	if (path_file)
		file = open(path_file, O_RDONLY);
	if (file < 0)
		return (OPEN_ERROR);
	while (*cpy_file == NULL && nb_alloc++ < NB_ALLOC_MAX && !errno)
		*cpy_file = ft_save_file(file, file_size);
	if (file)
		close (file);
	if (errno)
		return (READ_ERROR);
	if (NB_ALLOC_MAX <= nb_alloc)
	{
		errno = ENOMEM;
		return (OPEN_ERROR);
	}
	return (0);
}
