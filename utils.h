/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:20:15 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/05 16:45:35 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);

#endif