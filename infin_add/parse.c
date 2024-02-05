/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:35:28 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 13:17:21 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

static void	set_sizes(char **big, char *biggest, char **small, char *smallest)
{
	*big = biggest;
	*small = smallest;
	return ;
}

// returns 1 if it's the same number
int	find_sizes(char *left, char *right, char **big, char **small)
{
	int	i;

	if (ft_strlen(left) > ft_strlen(right))
	{
		set_sizes(big, left, small, right);
		return (0);
	}
	else if (ft_strlen(left) < ft_strlen(right))
	{
		set_sizes(big, right, small, left);
		return (0);
	}
	i = 0;
	while (left[i] != '\0')
	{
		if (left[i] > right[i])
		{
			set_sizes(big, left, small, right);
			return (0);
		}
		if (left[i] < right[i])
		{
			set_sizes(big, right, small, left);
			*big = right;
			*small = left;
			return (0);
		}
		i++;
	}
	set_sizes(big, left, small, right);
	return (1);
}

int		parse(char **argv, char **big, char **small)
{
	bool	neg_left;
	bool	neg_right;
	char	*left;
	char	*right;

	neg_left = false;
	neg_right = false;
	if (argv[1][0] == '-')
	{
		neg_left = true;
	}
	left = ft_strdup(argv[1] + neg_left);
	if (argv[2][0] == '-')
	{
		neg_right = true;
	}
	right = ft_strdup(argv[2] + neg_right);
	if (find_sizes(left, right, big, small) == 1)
		return (neg_left != neg_right);

	if (neg_left == true && neg_right == true)
		ft_putchar('-');
	else if (neg_left == true && **big == *left)
			ft_putchar('-');
	else if (neg_right && **big == *right)
		ft_putchar('-');	
	return (neg_left != neg_right);
}

// SITUATIE 1:	+ +				(addition,		+)
// SITUATIE 2:	- -				(addition,		-)
// SITUATIE 3:	+groot -klein	(subtraction,	+)
// SITUATIE 4:	+klein -groot	(subtraction,	-)
// SITUATIE 4:	+zelfde -zelfde	(subtraction,	+)
