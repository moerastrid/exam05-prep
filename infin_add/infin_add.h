/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_add.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:23:40 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 13:03:29 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_ADD_H
# define INFIN_ADD_H

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

//utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);

//parse (sets biggest and smallest, returns false:addition true:subtraction)
int		parse(char **argv, char **big, char **small);

#endif