/*
 * copy from http://c.biancheng.net/cpp/html/126.html
 */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	long int li;
	char buffer[256];
	printf ("Enter a long number: ");
	fgets(buffer, 256, stdin);
	li = atol(buffer);
	printf ("The value entered is %ld.\n", li);

	return 0;
}
