/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/13 20:08:29 by nlaerema         ###   ########.fr       */
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

char	*ft_strchars(char *str, char *to_find)
{
	unsigned int	i;

	if (!to_find[0])
		return (0);
	while (*str)
	{
		i = 0;
		while (to_find[i])
		{
			if (to_find[i] == *str)
				return (str);
			i++;
		}
		str++;
	}
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		src_sz;

	src_sz = ft_strlen(src);
	if (n < src_sz)
		src_sz = n;
	dest = malloc((src_sz + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[src_sz] = 0;
	while (src_sz--)
		dest[src_sz] = src[src_sz];
	return (dest);
}

int	substr_count(char *str, char *charset)
{
	char	*current;
	int		count;

	count = 0;
	current = str;
	while (current && *str)
	{
		current = ft_strchars(str, charset);
		if (current - str)
			count++;
		str = current + 1;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*current;
	int		split_sz;
	int		i;

	split_sz = substr_count(str, charset);
	split = malloc((split_sz + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	split[split_sz] = NULL;
	while (i < split_sz)
	{
		current = ft_strchars(str, charset);
		if (!current && current - str)
			split[i++] = ft_strndup(str, ft_strlen(str));
		else if (current - str)
			split[i++] = ft_strndup(str, current - str);
		str = current + 1;
	}
	return (split);
}

/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**split;

	if (2 < argc)
	{
		split = ft_split(argv[1], argv[2]);
		while (*split)
			printf("%s\n", *(split++));
	}
	else
		printf("required 'str' 'charset'\n");
}
*/
