/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/27 21:09:56 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strslen(int size, char **strs)
{
	int	len;

	len = 0;
	while (size--)
		len += ft_strlen(strs[size]);
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	len;

	len = -1;
	while (src[++len])
		dest[len] = src[len];
	dest[len] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	sep_sz;	
	unsigned int	strs_sz;
	unsigned int	offset;
	char			*dest;
	int				i;

	sep_sz = ft_strlen(sep);
	strs_sz = ft_strslen(size, strs);
	dest = malloc((strs_sz + (size - (0 < size)) * sep_sz + 1) * sizeof(char));
	if (dest)
		dest[0] = 0;
	i = 0;
	offset = 0;
	while (i < size && dest)
	{
		ft_strcpy(dest + offset, strs[i]);
		offset += ft_strlen(strs[i]);
		i++;
		if (i < size)
		{
			ft_strcpy(dest + offset, sep);
			offset += sep_sz;
		}
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *dest; 70         }


	if (1 < argc)
	{
		dest = ft_strjoin(argc - 2, argv + 2, argv[1]);
		printf("%s\n", dest);
	}
	else
		printf("required 'sep' ...\n");
	return (0);
}
*/
