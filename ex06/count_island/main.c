/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 13:02:27 by ageels        #+#    #+#                 */
/*   Updated: 2024/05/13 15:00:28 by ageels        ########   odam.nl         */
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
		count++;
	}
	close(fd);
	return (count);
}

void	make_map(const char *input, const size_t row_length, const size_t row_count)
{
	char	map[row_length + 1][row_count];
	int		fd;
	int		n;
	char	buf[1];

	fd = open(input, O_RDONLY);
	n = 1;
	while (n > 0)
	{
		n = read(fd, &buf, 1);
		if (buf[0] == '\n') {
			buf[0] = '\0';
		} else {
			*(char*)map = buf[0];
		}
	}
	close(fd);
	
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j]!= 0 && map[i][j] )
		{
			ft_putchar(map[i][j]);
			j++;
		}
		i++;
	}

}

int	print_newline_return_zero(void)
{
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	size_t	row_lenght;
	size_t	row_count;
	// char	**map;

	if (argc != 2)
		print_newline_return_zero();
	row_lenght = get_row_length(argv[1]);
	if (row_lenght == 0)
		print_newline_return_zero();
	row_count = get_row_count(argv[1], row_lenght);
	if (row_count == 0)
		print_newline_return_zero();
	make_map(argv[1], row_lenght, row_count);
	
	printf("%s\n%ld\n%ld\n", argv[1], row_lenght, row_count);
	return (0);
}
