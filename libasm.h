/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 13:59:18 by averheij      #+#    #+#                 */
/*   Updated: 2020/11/10 15:00:53 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBASM_H
# define LIBASM_H

# include <stdlib.h>

extern size_t	_ft_strlen(const char *str);
extern char		*_ft_strcpy(char *dest, const char *src);
extern int		_ft_strcmp(const char *s1, const char *s2);
extern ssize_t	_ft_write(int fd, const void *buf, size_t count);
extern ssize_t	_ft_read(int fd, const void *buf, size_t count);
extern char		*_ft_strdup(const char *s);

#endif
