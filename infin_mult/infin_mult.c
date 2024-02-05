/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:18 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:51:35 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	add(char **result, size_t res_len, size_t location, int number)
{
	number += (*result)[res_len - location] - '0';
	if (number >= 10)
	{
		add(result, res_len, location + 1, number / 10);
		number = number % 10;
	}
	(*result)[res_len - location] = number + '0';
}

void	multiply(char *big, char *small)
{
	char	*result = ft_calloc(sizeof(char), res_len + 1);
	size_t	res_len = ft_strlen(big) + ft_strlen(small);
	int		number = 0;
	size_t	i = 0;

	while (i < res_len)
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';

	i = 0;
	while (i < ft_strlen(big))
	{		
		size_t	j = 0;
		while (j < ft_strlen(small))
		{
			number = (small[j] - '0') * (big[i] - '0');
			add(&result, res_len, res_len - (i + j) - 1, number);
			j++;
		}
		i++;
	}

	i = 0;
	while ((result[i]) == '0' || (result[i]) == '\0')
		i++;
	ft_putstr(&(result[i]));
	free(result);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		ft_putstr("0\n");
		return (0);
	}
	char	*big = NULL;
	char	*small= NULL;

	if (parse(argv, &big, &small) == false)
		ft_putchar('-');
	multiply(big, small);
	ft_putchar('\n');
	free(big);
	free(small);
	return (0);
}