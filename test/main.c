/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 12:48:35 by averheij      #+#    #+#                 */
/*   Updated: 2020/06/05 16:11:05 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define	PRINT	1
#define VERBOSE	1
#define	RTESTS	100
#define	FAILEXIT	0
#define SIZE		999999

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dest, const char *src);

void	error_out(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int		rand_in_range(int min, int max)
{
	return (rand() % (max + 1 - min) + min);
}

void	randa_nfill(char *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		arr[i] = rand_in_range(32, 127);
		i++;
	}
	arr[i] = '\0';
}

int		strlen_test(char *str)
{
	size_t	sys;
	size_t	ft;

	sys = strlen(str);
	ft = ft_strlen(str);
	printf("%-6lu %-6lu: %d, %.57s\n", sys, ft, sys == ft, str);
	if (FAILEXIT && sys != ft)
		error_out("Failed strlen test");
	return (!(sys == ft));
}

int		strcpy_test(char *dest, const char *src)
{
	char 	*ret;
	int		fail;
	int		cmp;

	fail = 0;
	bzero(dest, SIZE);
	ret = ft_strcpy(dest, src);
	cmp = strcmp(dest, src);
	if (cmp)
		fail = 1;
	else if (ret != dest)
		fail = 1;
	printf("%-3d %d   : %d, %.60s\n", cmp, ret == dest, !fail, dest);
	if (FAILEXIT && fail)
		error_out("Failed strcpy test");
	return (fail);
}

int	main()
{
	char	*buf;
	char	*buf2;
	size_t	size;
	size_t	testsize;
	int		i;
	int		fail;

	fail = 0;
	size = SIZE;
	printf("buf max: %lu\n", size);
	buf = calloc(size, sizeof(char));
	if (!buf)
		error_out("Buf alloc failed");
	buf2 = calloc(size, sizeof(char));
	if (!buf2)
		error_out("Buf alloc failed");

	//STRLEN TESTS
	printf("\n\t\t\t------strlen tests------\n");
	printf("sys == ft    : ?, str\n");
	fail += strlen_test("");
	fail += strlen_test("S");
	fail += strlen_test("wow they're getting pretty crazy now &!@#$");
	fail += strlen_test("this is as long as we can get without line breaks still norm");
	randa_nfill(buf, size);
	fail += strlen_test(buf);
	i = 0;
	while (i < RTESTS)
	{
		randa_nfill(buf, rand_in_range(0, size));
		fail += strlen_test(buf);
		i++;
	}

	//STRCPY TESTS
	printf("\n\t\t\t------strcpy tests------\n");
	printf("len    cmp ret : ?, str\n");
	strcpy(buf, "");//Singletest function
	printf("%-6lu ", 0UL);
	fail += strcpy_test(buf2, buf);
	strcpy(buf, "S");
	printf("%-6lu ", 1UL);
	fail += strcpy_test(buf2, buf);
	randa_nfill(buf, size);
	printf("%-6lu ", size);
	fail += strcpy_test(buf2, buf);
	i = 0;//Multitest function
	while (i < RTESTS)
	{
		testsize = rand_in_range(0, size);
		randa_nfill(buf, testsize);
		printf("%-6lu ", testsize);
		fail += strcpy_test(buf2, buf);
		i++;
	}

	if (fail)
		printf("Boo, you failed some tests! :(\n");
	else
		printf("Everything passed! :))\n");

}

