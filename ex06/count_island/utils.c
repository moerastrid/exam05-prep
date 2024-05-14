/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 13:02:05 by ageels        #+#    #+#                 */
/*   Updated: 2024/05/14 14:32:31 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(const char c) {
	write(1, &c, 1);
}

void	ft_putstr(const char *str) {
	int	i = 0;

	while (str[i] != '\0') {
		ft_putchar(str[i]);
		i++;
	}
}

size_t	ft_strlen(const char *str) {
	size_t	i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

// void	*ft_calloc(int amount, size_t size)
// {
// 	size_t	i;
// 	void	*pointer;

// 	pointer = malloc(amount * size);
// 	if (pointer == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < amount * size)
// 	{
// 		*((char *)pointer) = '\0';
// 		i++;
// 	}
// 	return (pointer);
// }

char	*ft_strdup(const char *str) {
	char	*retstr;
	size_t	i;

	retstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\0') {
		retstr[i] = str[i];
		i++;
	}
	retstr[i] = str[i];
	return (retstr);
}

//gcc -Wall -Werror -Wextra main.c utils.c && valgrind ./a.out example2.txt