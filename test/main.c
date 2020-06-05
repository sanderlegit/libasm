/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 12:48:35 by averheij      #+#    #+#                 */
/*   Updated: 2020/06/05 17:50:57 by averheij      ########   odam.nl         */
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
extern int		ft_strcmp(const char *s1, const char *s2);

void	error_out(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int		rand_in_range(int min, int max)
{
	return (rand() % (max + 1 - min) + min);
}

char	*randa_nfill(char *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		arr[i] = rand_in_range(32, 127);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int		strlen_test(char *str)
{
	size_t	sys;
	size_t	ft;

	sys = strlen(str);
	ft = ft_strlen(str);
	printf("%-6lu %-6lu: %d, %-62.62s\n", sys, ft, sys == ft, str);
	if (FAILEXIT && sys != ft)
		error_out("Failed strlen test");
	return (!(sys == ft));
}

int		strcpy_test(char *dest, const char *src, size_t size)
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
	printf("%-6lu %-3d %d   : %d, %-61.61s\n", size, cmp, ret == dest, !fail, dest);
	if (FAILEXIT && fail)
		error_out("Failed strcpy test");
	return (fail);
}

int		strcmp_test(const char *s1, const char *s2)
{
	int 	sys;
	int		ft;

	sys = strcmp(s1, s2);
	ft = ft_strcmp(s1, s2);
	printf("%-3d %-3d: %d, %-33.33s| %-33.33s\n", sys, ft, sys == ft, s1, s2);
	if (FAILEXIT && sys != ft)
		error_out("Failed strcpy test");
	return (sys != ft);
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
	fail += strlen_test(randa_nfill(buf, size));
	i = 0;
	while (i < RTESTS)
	{
		fail += strlen_test(randa_nfill(buf, rand_in_range(0, size)));
		i++;
	}

	//STRCPY TESTS
	printf("\n\t\t\t------strcpy tests------\n");
	printf("len    cmp ret : ?, str\n");
	fail += strcpy_test(buf2, strcpy(buf, ""), 0);
	fail += strcpy_test(buf2, strcpy(buf, "S"), 1);
	fail += strcpy_test(buf2, randa_nfill(buf, size), size);
	i = 0;
	while (i < RTESTS)
	{
		testsize = rand_in_range(0, size);
		fail += strcpy_test(buf2, randa_nfill(buf, testsize), testsize);
		i++;
	}

	//STRCMP
	printf("\n\t\t\t------strcmp tests------\n");
	printf("sys ft : ?, s1						s2\n");
	fail += strcmp_test("hello", "hello");
	fail += strcmp_test("its me", "its me your friend");
	fail += strcmp_test("abdc", "abcc");
	fail += strcmp_test("ABBA", "ABZA");
	//create a random nlength string, copy rand n chars to second string, add n random chars to end of second string

	if (fail)
		printf("Boo, you failed some tests! :(\n");
	else
		printf("Everything passed! :))\n");

}

