/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 12:48:35 by averheij      #+#    #+#                 */
/*   Updated: 2020/06/15 15:21:45 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "test.h"


int		open_safe(char *filename, int mode, int priv)
{
	int		fd;

	fd = open(filename, mode|O_CREAT, priv);
	if (fd == -1)
		fd = open(filename, mode, priv);
	if (fd == -1)
		error_out("Failed to open fd");
	return fd;
}

void	close_safe(int fd)
{
	if (close(fd) == -1)
		error_out("Failed to close fd");
}

void	error_out(char *str)
{
	/*printf("%s\n", str);*/
	perror(str);
	exit(1);
}

long long	rand_in_range(long long min, long long max)
{
	return (rand() % (max + 1 - min) + min);
}

char	*randa_nfill(char *arr, size_t n)
{
	size_t	i;

	bzero(arr, n);
	i = 0;
	while (i < n - 1)
	{
		arr[i] = rand_in_range(32, 127);
		i++;
	}
	return (arr);
}

int		main()
{
	char	*buf;
	char	*buf2;
	char	*buf3;
	size_t	testsize;
	int		fail;
	//Array of max len values to loop over as SIZE for random tests

	ssize_t	ret;

	fail = 0;
	printf("buf max: %d\n", SIZE);
	buf = calloc(SIZE, sizeof(char));
	buf2 = calloc(SIZE, sizeof(char));
	buf3 = calloc(SIZE, sizeof(char));
	if (!buf || !buf2 || !buf3)
		error_out("Buf alloc failed");

	//strlen tests
	printf("\n\t\t\t------strlen tests------\n");
	printf("sys == ft    : ?, str\n");
	fail += strlen_test("");
	fail += strlen_test("S");
	fail += strlen_test("wow they're getting pretty crazy now &!@#$");
	fail += strlen_test("this is as long as we can get a string and stillnorm");
	fail += strlen_test(randa_nfill(buf, SIZE));
	strlen_test_rand(buf, &fail, SIZE);

	//strcpy tests
	printf("\n\t\t\t------strcpy tests------\n");
	printf("len    cmp ret : ?, str\n");
	fail += strcpy_test(buf2, strcpy(buf, ""), 0);
	fail += strcpy_test(buf2, strcpy(buf, "S"), 1);
	fail += strcpy_test(buf2, randa_nfill(buf, SIZE), SIZE);
	strcpy_test_rand(buf, buf2, &fail, SIZE);

	//strcmp tests
	printf("\n\t\t\t------strcmp tests------\n");
	printf("sys ft : ?, s1				     s2\n");
	fail += strcmp_test("", "");
	fail += strcmp_test("S", "S");
	fail += strcmp_test("", "S");
	fail += strcmp_test("Q", "S");
	fail += strcmp_test("Q", "");
	fail += strcmp_test("hello", "hello");
	fail += strcmp_test("its me", "its me your friend");
	fail += strcmp_test("abdc", "abcc");
	fail += strcmp_test("ABBA", "ABZA");
	fail += strcmp_test("ABZA", "ABBA");
	strcmp_test_rand(buf, buf2, &fail, SIZE);

	//write tests
	printf("\n\t\t\t------write tests-------\n");
	printf("ret           errno       str\n");
	printf("sys    ft     sys ft : ?  sys			      ft\n");
	fail += write_fd_test(-1, buf, buf2);
	fail += write_fd_test(0, buf, buf2);
	fail += write_fd_test(1, buf, buf2);
	fail += write_fd_test(2, buf, buf2);
	fail += write_test(strcpy(buf, ""), buf2, buf3, 0);
	fail += write_test(strcpy(buf, "b"), buf2, buf3, 1);
	fail += write_test(randa_nfill(buf, SIZE), buf2, buf3, SIZE);
	write_test_rand(buf, buf2, buf3, &fail, SIZE);

	//read tests
	printf("\n\t\t\t------read tests--------\n");
	printf("ret           errno       str\n");
	printf("sys    ft     sys ft : ?  sys			      ft\n");
	fail += read_test(strcpy(buf, "read test numero uno"), buf2, buf3, 20);
	read_test_rand(buf, buf2, buf3, &fail, SIZE);

	if (fail)
		printf("Boo, you failed %d tests! :(\n", fail);
	else
		printf("Everything passed! :))\n");

}

