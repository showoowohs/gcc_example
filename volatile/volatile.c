#include <stdio.h>

void main(void)
{
	unsigned long v1 = 0x00001111;
	unsigned long v2 = 0x00001202;
	unsigned long v;
	printf("~v2=%p\n", ~v2);
	v = v1&(~v2);
	printf("v=%x\n", v);
	v = v | v2;
	printf("v=%x\n", v);

}

