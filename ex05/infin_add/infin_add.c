/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_add.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:23:46 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:48:52 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

void	add_to_prev(char **result, int i)
{
	if (i == 0) 
	{
		ft_putchar('1');
		return ;
	}
	if ((*result)[i - 1] != '9')
	{
		(*result)[i - 1] += 1;
		return ;
	}
	(*result)[i - 1] = '0';
	add_to_prev(result, i - 1);
	return ;
}

void	subtract_from_prev(char **result, size_t i)
{
	if ((*result)[i - 1] != 0)
	{
		(*result)[i - 1] -= 1;
		return ;
	}
	subtract_from_prev(result, i - 1);
}

void	add(char *big, char *small)
{
	char	*result = ft_calloc(sizeof(char), ft_strlen(big) + 1);
	size_t	offset = ft_strlen(big) - ft_strlen(small);
	size_t	i = 0;
	int		temp = 0;

	while (big[i])
	{
		if (i < offset)
			result[i] = big[i];
		else
		{
			temp = (big[i] - '0') + (small[i - offset] - '0');
			if (temp >= 10)
			{
				temp -= 10;
				add_to_prev(&result, i);
			}
			result[i] = temp + '0';
		}
		i++;
	}
	result[i] = '\0';
	ft_putstr(result);
	free(result);
}

void	subtract(char *big, char *small)
{
	char	*result = ft_calloc(sizeof(char), ft_strlen(big) + 1);
	size_t	offset = ft_strlen(big) - ft_strlen(small);
	size_t	i = 0;
	int		temp = 0;

	while (big[i])
	{
		if (i < offset)
			result[i] = big[i];
		else
		{
			temp = (big[i] + '0') - (small[i - offset] + '0');
			if (temp < 0)
			{
				temp += 10;
				subtract_from_prev(&result, i);
			}
			result[i] = temp + '0';
		}
		i++;
	}
	result[i] = '\0';
	i = 0;
	while (result[i] == '0')
		i++;
	ft_putstr(&result[i]);
	free(result);
}

int	main(int argc, char **argv)
{
	bool	subtraction;
	char	*big;
	char	*small;

	if (argc != 3)
		return (0);
	subtraction = parse(argv, &big, &small);
	if (subtraction)
		subtract(big, small);
	else
		add(big, small);
	ft_putchar('\n');
	free(big);
	free(small);
	return (0);
}
