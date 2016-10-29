#include <stdio.h>
#include <gnu/libc-version.h>

void main(void)
{
	const char *gnu_get_libc_version(void);
	printf("My PC GNU version is %s\n", gnu_get_libc_version());
}

