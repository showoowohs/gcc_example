#include <stdio.h>

#define AC (0x01)
void main(void)
{
	int ret = 1;
	ret &= ~AC;

	printf("%d\n", ret);
	printf("%x\n", ret);
}

