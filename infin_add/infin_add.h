/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_add.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 12:23:40 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 16:45:59 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_ADD_H
# define INFIN_ADD_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
#include "../utils.h"

//parse (sets biggest and smallest, returns false:addition true:subtraction)
int		parse(char **argv, char **big, char **small);

#endif