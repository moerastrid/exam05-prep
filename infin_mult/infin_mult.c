/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:18 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 17:02:27 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	multiply(char *big, char *small)
{
	char	*result = NULL;
	size_t	big_len = ft_strlen(big);
	size_t	small_len = ft_strlen(small);
	size_t	res_len = big_len + small_len - 1;

	result = ft_calloc(sizeof(char), big_len + small_len);

	size_t i = 0;
	while(i < res_len)
	{

		
		
		i++;
	}
	result[i] = '\0';

	ft_putstr(result);
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

	ft_putstr("\nBIG:\t");
	ft_putstr(big);
	ft_putstr("\nSMALL:\t");
	ft_putstr(small);

	ft_putchar('\n');
	
	return (0);
}