/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:35:28 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:52:52 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

static int	set_sizes(char **big, char *biggest, char **small, char *smallest)
{
	*big = biggest;
	*small = smallest;
	return (0);
}

// returns 1 if it's the same number
int	find_sizes(char *left, char *right, char **big, char **small)
{
	if (ft_strlen(left) > ft_strlen(right))
		return (set_sizes(big, left, small, right));
	else if (ft_strlen(left) < ft_strlen(right))
		return (set_sizes(big, right, small, left));

	int	i = 0;
	while (left[i] != '\0')
	{
		if (left[i] > right[i])
			return (set_sizes(big, left, small, right));
		if (left[i] < right[i])
			return (set_sizes(big, right, small, left));
		i++;
	}
	set_sizes(big, left, small, right);
	return (1);
}

int	parse(char **argv, char **big, char **small)
{
	bool	neg_left = false;
	bool	neg_right = false;
	if (argv[1][0] == '-';
		neg_left = true;
	if (argv[2][0] == '-')
		neg_right = true;

	char	*left = ft_strdup(argv[1] + neg_left);
	char	*right = ft_strdup(argv[2] + neg_right);
	if (find_sizes(left, right, big, small) == 1)
		return (neg_left != neg_right);
	if ((neg_left == true && neg_right == true) \
		|| (neg_left == true && *big == left) \
		|| (neg_right && *big == right))
		ft_putchar('-');
	return (neg_left != neg_right);
}

