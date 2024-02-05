/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:29:52 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 12:45:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*point;
	int		i;

	point = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (point == NULL)
		return (point);
	i = 0;
	while (str[i] != '\0')
	{
		point[i] = str[i];
		i++;
	}
	point[i] = '\0';
	return (point);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
