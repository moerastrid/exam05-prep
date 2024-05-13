/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 13:02:05 by ageels        #+#    #+#                 */
/*   Updated: 2024/05/13 15:01:21 by ageels        ########   odam.nl         */
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
