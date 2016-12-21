/*
 * reference: http://www.prudentman.idv.tw/2007/11/big-endianlittle-endian.html 
 *
 * 如果你在文件上看到一個雙字組的data，Ex: long MyData=0x12345678，要寫到從0x0000開始的記憶體位址時
 *
 * 如果是Big Endian的系統：
 *       存到記憶體會變成 0x12 0x34 0x56 0x78，最高位元組在位址最低位元，最低位元組在位址最高位元，依次排列
 *
 * 如果是Little Endian的系統：
 *       存到記憶體會變成 0x78 0x56 0x34 0x12，最低位元組在最低位元，最高位元組在最高位元，反序排列。
 */
#include <stdio.h>

typedef union { 
	long l;
	unsigned char c[4];
} EndianTest; 

int main(int argc, char* argv[]) {
	EndianTest a;
	a.l=0x12345678;
	int i=0;
	if((a.c[0] == 0x78) && (a.c[1] == 0x56) && (a.c[2] == 0x34) && (a.c[3] == 0x12)) {
		printf("This system is 'Little Endian'.\n"); 
	}else if((a.c[0] == 0x12) && (a.c[1] == 0x34) && (a.c[2] == 0x56) && (a.c[3] == 0x78)) {
		printf("This system is 'Big Endian'.\n");
	}else {
		printf("This system is 'Unknown Endian'.\n");
	} 
	printf("for a long variable value is 0x%lX\n", a.l);
	printf("and its storage order in memory :\n");
	for(i=0;i<4;i++) 
		printf("%p : 0x%02X\n", &a.c[i], a.c[i]); 
	return 0;
}
