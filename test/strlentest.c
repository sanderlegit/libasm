/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlentest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 12:53:50 by averheij      #+#    #+#                 */
/*   Updated: 2020/06/15 14:52:34 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "test.h"

void	strlen_test_rand(char *buf, int *fail, size_t size)
{
	int i;

	i = 0;
	while (i < RTESTS)
	{
		(*fail) += strlen_test(randa_nfill(buf, rand_in_range(1, size)));
		i++;
	}
}

int		strlen_test(char *str)
{
	size_t	sys;
	size_t	ft;

	sys = strlen(str);
	ft = ft_strlen(str);
	printf("%-6lu %-6lu: %d, %-62.62s\n", sys, ft, sys != ft, str);
	if (FAILEXIT && sys != ft)
		error_out("Failed strlen test");
	return (sys != ft);
}
