/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/07/25 01:48:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include "ft_file.h"
# include <stdint.h>
# include <stdio.h>

# define NO_INI SIZE_MAX

# define EMPTY SIZE_MAX
# define BLOCK 0

# define ERROR_GET_MAP 1
# define ERROR_PARSE_MAP 2
# define ERROR_FIND_SOLUCE 3
# define ERROR_PRINT_SOLUCE 4

typedef struct s_coord
{
	size_t	line;
	size_t	col;	
}	t_coord;

/*
cette structure represente une map

file: fichier brute de la map
map: map sous forme de tableau de int pour faire les calcules == map[line][col]
empty: le charactere vide
block: le charactere obstacle
fill: le charactere plein
line: le nombre de ligne
col: le nombre de colonne
soluce: les coord du coin en bas a droite du carrer trouver
*/
typedef struct s_map
{
	size_t	**map;
	char	*file;
	char	empty;
	char	block;
	char	fill;
	size_t	line;
	size_t	col;
	t_coord	soluce;
}	t_map;

/*
initilaise une map en ouvrant le fichier portant le nom "map_path_name"

map = NULL
file = fichier de la map
empty = 0
block = 0
fill = 0
line = 0
col = 0
soluce = NO_INI
*/
int		ft_get_map(t_map *new_map, char *map_path_name);

/*
parse la map et initialise la map sous forme de tableau de int

map = la map (vide = EMPTY, obstacle = BLOCK)
file = fichier de la map
empty = le charactere vide
block = le charactere obstacle
fill = le charactere plein
line = nombre de ligne de la map
col = nombre de colonne de la map
soluce = NO_INI
*/
int		ft_parse_map(t_map *map);

/*
essaye de trouver une solution

map = la map (vide = {1..n}, obstacle = 0})
file = fichier de la map
empty = le charactere vide
block = le charactere obstacle
fill = le charactere plein
line = nombre de ligne de la map
col = nombre de colonne de la map
soluce = coord de la soluce ou NO_INI
*/
int		ft_find_soluce(t_map *map);

/*
affiche la solution trouver
*/
int		ft_print_soluce(t_map *map);

/*
free les 2 map (int et char) et ecrit "map error" dans fd = 2 si (0 < error)

map = NULL
file = NULL
empty = 0
block = 0
fill = 0
line = 0
col = 0
soluce = NO_INI
*/
int		ft_free(int error, t_map *map);

t_coord	ft_set_coord(size_t	line, size_t col);
int		ft_solution_found(t_map *map);
size_t	ft_get_square_size(t_map *map);

void	ft_putchar_fd(int fd, char c);
int		ft_isprint(char c);

#endif
