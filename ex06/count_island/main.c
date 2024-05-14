/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 13:02:27 by ageels        #+#    #+#                 */
/*   Updated: 2024/05/14 15:17:34 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

size_t	get_row_length(const char *input)
{
	int		fd;
	int		n;
	size_t	length;
	char	buf[1];

	length = 0;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, &buf, 1);
		if (n > 0 && buf[0] != '\n')
			length++;
		else
			break ;
	}
	close(fd);
	return (length);
}

size_t	get_row_count(const char *input, const size_t row_length)
{
	int		fd;
	int		n;
	size_t	count;
	char	buf[row_length + 1];

	count = 0;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, &buf, row_length + 1);
		if (n <= 0)
			break;
		count++;
	}
	close(fd);
	return (count);
}

char	**get_map(const char *input, const size_t row_length, const size_t row_count)
{
	char	**map;
	int		fd;
	int		n;
	char	buf[row_length + 1];
	size_t	i;

	map = malloc((row_count + 1) * sizeof(char *));
	fd = open(input, O_RDONLY);
	n = 1;
	i = 0;
	while (n > 0) {
		n = read(fd, &buf, row_length + 1);
		if (n <= 0)
			break ;
		buf[row_length + 1] = '\0';
		map[i] = ft_strdup(buf);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	print_newline_return_zero(void)
{
	ft_putchar('\n');
	return (0);
}

void	print_map(char **map)
{
	size_t	i;
	
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
}

void	free_map(char **map)
{
	size_t	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}



// bool	find_isle(char **map, char n, size_t row_length, size_t row_count) {
// 	size_t	y;
// 	size_t	x;
// 	bool	found = false;

// 	y = 0;
// 	while (map[y] != NULL) {
// 		x = 0;
// 		while(map[y][x] != '\0') {
// 			if (map[y][x] == 'X' && found == false) {
// 				found = true;
// 				map[y][x] = n;
// 			} else if (map[y][x] == 'X' && found == true) {
// 				if (x != 0) {
// 					if (map[y][x - 1] == n) {
// 						map[y][x] = n;
// 					}
// 				}
				
// 				if (x != row_length - 1) {
// 					if (map[y][x + 1] == n) {
// 						map[y][x] = n;
// 					}
// 				}
				
// 				if (y != 0) {
// 					if (map[y - 1][x] == n) {
// 						map[y][x] = n;
// 					}
// 				}
				
// 				if (y != row_count - 1) {
// 					if (map[y + 1][x] == n) {
// 						map[y][x] = n;
// 					}
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (found);
// }

int	the_virus(size_t x, size_t y, size_t row_length, size_t row_count, char **map, char n) {
	int count = 0;

	if (map[y][x] == 'X')
	{
		count+=1;
		map[y][x] = n;
		if (x != 0)
			count += the_virus(x - 1, y, row_length, row_count, map, n);
		if (x != row_length - 1)
			count += the_virus(x + 1, y, row_length, row_count, map, n);
		if (y != 0)
			count += the_virus(x, y - 1, row_length, row_count, map, n);
		if (y != row_count - 1)
			count += the_virus(x, y + 1, row_length, row_count, map, n);
	}
	return (count);	
}


int	find_isle(char **map, char n, size_t row_length, size_t row_count) {
	size_t	y;
	size_t	x;
	int count = 0;
	int biggest = 0;

	(void)row_count;
	(void)row_length;

	y = 0;
	while (map[y] != NULL) {
		x = 0;
		while(map[y][x] != '\0') {
			if (map[y][x] == 'X') {
				count = the_virus(x, y, row_length, row_count, map, n);
				if (biggest < count)
					biggest = count;
				n++;
			}
			x++;
		}
		y++;
	}
	return biggest;
}


int	main(int argc, char **argv)
{
	size_t	row_lenght;
	size_t	row_count;
	char	**map;

	if (argc != 2)
		print_newline_return_zero();
	row_lenght = get_row_length(argv[1]);
	if (row_lenght == 0)
		print_newline_return_zero();
	row_count = get_row_count(argv[1], row_lenght);
	if (row_count == 0)
		print_newline_return_zero();
	map = get_map(argv[1], row_lenght, row_count);
	print_map(map);
	printf("\nINFO:\n%s\n%ld\n%ld\n\n", argv[1], row_lenght, row_count);
	
	printf("\nbiggest: %d\n\n", find_isle(map, '0', row_lenght, row_count));

	print_map(map);

	free_map(map);
	return (0);
}
