/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmptest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 13:18:04 by averheij      #+#    #+#                 */
/*   Updated: 2020/06/15 14:40:58 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "test.h"

void	strcmp_test_rand(char *buf, char *buf2, int *fail, size_t size)
{
	int		i;
	int		testsize;
	int		testsize2;

	i = 0;
	while (i < RTESTS)
	{
		//fill n bytes
		randa_nfill(buf2, rand_in_range(1, size));
		//copy n bytes
		testsize = rand_in_range(1, size);
		strncpy(buf, buf2, testsize);
		//50 / 50 chance to write testsize - size more bytes
		testsize2 = rand_in_range((size - testsize) * -1, size - testsize);
		if (testsize2 > 0)
			randa_nfill((buf + testsize), testsize2);
		(*fail) += strcmp_test(buf2, buf);
		i++;
	}
}

int		strcmp_test(const char *s1, const char *s2)
{
	int 	sys;
	int		ft;

	sys = strcmp(s1, s2);
	ft = ft_strcmp(s1, s2);
	printf("%-3d %-3d: %d, %-33.33s %-33.33s\n", sys, ft, sys != ft, s1, s2);
	if (FAILEXIT && sys != ft)
		error_out("Failed strcmp test");
	return (sys != ft);
}
