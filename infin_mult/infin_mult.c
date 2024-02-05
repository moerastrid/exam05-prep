/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:23:46 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 12:48:05 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

int	main(int argc, char **argv)
{
	bool	negative;
	char	*big;
	char	*small;

	if (argc != 3)
	{
		write(1, "Usage: ./a.out <number> <number>\n", 34);
		return (0);
	}
	negative = parse(argv, &big, &small);
	printf("big : %s\n", big);
	printf("small : %s\n", small);
	printf("negative : %d\n", negative);
	
	if (negative == true)
		ft_putchar('-');
	ft_putchar('\n');
	
	free(big);
	free(small);
	return (0);
}
