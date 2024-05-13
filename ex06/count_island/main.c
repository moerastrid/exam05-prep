/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 13:02:27 by ageels        #+#    #+#                 */
/*   Updated: 2024/05/13 18:33:17 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
	printf("\n%s\n%ld\n%ld\n", argv[1], row_lenght, row_count);

	
	// find_isle()

	free_map(map);
	return (0);
}
