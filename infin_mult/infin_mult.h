/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:23:40 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 12:46:06 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

//utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);

//parse (sets biggest and smallest, returns 0 if addition, 1 if minus)
int		parse(char **argv, char **big, char **small);

#endif