/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:18 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:29:03 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	add(char **result, size_t res_len, size_t location, int number)
{
	if (number > 10)
	{
		add(result, res_len, location + 1, number / 10);
		number = number % 10;
	}
	
	int old = (*result)[res_len - location] - '0';
	int new = number + old;
	if (new >= 10)
	{
		add(result, res_len, location + 1, new / 10);
		new = new % 10;
	}
	(*result)[res_len - location] = new + '0';
}

void	multiply(char *big, char *small)
{
	char	*result = NULL;
	size_t	big_len = ft_strlen(big);
	size_t	small_len = ft_strlen(small);
	size_t	res_len = big_len + small_len;

	int number = 0;
	result = ft_calloc(sizeof(char), res_len + 1);
	size_t i = 0;
	while(i < res_len) {
		result[i] = '0';
		i++;
	}
	result[i] = '\0';

	i = 0;
	while(i < big_len)
	{		
		size_t j = 0;
		while (j < small_len)
		{
			number = (small[j] - '0') * (big[i] - '0');

			size_t location = res_len - (i + j) - 1;
			#include <stdio.h>
			printf("i: %ld\tj: %ld\tnumber: %d\tlocation: %ld\n", i, j, number, location);

			add(&result, res_len, location, number);
			j++;
		}
		i++;
	}

	i = 0;
	while((result[i]) == '0' || (result[i]) == '\0') {
		i++;
	}

	ft_putstr(&(result[i]));
	free(result);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Usage: ./a.out <number> <number>\n", 34);
		return (0);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		ft_putchar('0');
		return(0);
	}
	
	char *big = NULL;
	char *small= NULL;
	
	if (parse(argv, &big, &small) == false)
		ft_putchar('-');

	multiply(big, small);

	// ft_putstr("\nBIG:\t");
	// ft_putstr(big);
	// ft_putstr("\nSMALL:\t");
	// ft_putstr(small);

	ft_putchar('\n');
	
	return (0);
}