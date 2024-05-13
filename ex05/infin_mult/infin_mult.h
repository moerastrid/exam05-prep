/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_mult.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:15 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 19:52:10 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../utils.h"

//parse
bool	parse(char **argv, char **big, char **small);

#endif