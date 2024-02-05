/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_mult.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:11 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:53:32 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

static void	set_sizes(char **big, char *biggest, char **small, char *smallest)
{
	*big = biggest;
	*small = smallest;
}

void	find_sizes(char **big, char **small, char *left, char *right)
{
	if (ft_strlen(left) > ft_strlen(right))
		return (set_sizes(big, left, small, right));
	if (ft_strlen(right) > ft_strlen(left))
		return (set_sizes(big, right, small, left));

	int	i = 0;
	while (left[i] != '\0')
	{
		if (left[i] > right[i])
			return (set_sizes(big, left, small, right));
		if (right[i] > left[i])
			return (set_sizes(big, right, small, left));
		i++;
	}
	return (set_sizes(big, left, small, right));
}

bool parse(char **argv, char **big, char **small)
{
	char	*left = argv[1];
	char	*right = argv[2];
	bool	neg_left = false;
	bool	neg_right = false;

	if (left[0] == '-') 
	{
		neg_left = true;
		left++;
	}
	if (right[0] == '-')
	{
		neg_right = true;
		right++;
	}
	find_sizes(big, small, left, right);
	return (neg_left == neg_right);
}