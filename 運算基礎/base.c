/*
 * referance http://shukaiyang.myweb.hinet.net/cpp/bitwiseop.zhtw.htm
 *  (1) 邏輯運算觀念
 *  A AND B 只有在兩者皆為 1 的時候才會 1
 *  A OR B 則是兩者有ㄧ者為1 的時候就會1
 *  A XOR B 是 A 與 B 不相等的時候為 1
 *  NOT 則是單純地 0 變  1、1 變 0
 *
 *  if ( a != 0 && b != 0) { ...  }  // 連續兩個 && 是邏輯判斷的 AND
 *  if ( a && b ) {  ...  }          // 同上
 *  if ( a & b ) { ...  }            // 這是 AND 位元運算，如果 a bitwise-AND b 的結果不為零...
 *  char * ptr = & a;                // & 當一元運算子的時候是對變數取位址
 *
 *  所謂的2進位/10進位/16進位意思就是以2/10/16為底
 *  如果要算 2進位就是:  10進位數字/2
 *  如果要算 16進位就是: 10進位數字/16
 *
 *  (2) 大小
 *  unsigned char 有 8 bits
 *  0xcd = 1100 1101  ---> 當中 c 就是一組(4 bit)
 *
 */
#include <stdio.h>

void main(void)
{
	// 以下分別以進位與進位表示法來指定 a 與 b:
	unsigned char a = 205;       // 即 1100 1101, 相當於 a = 0xcd
	unsigned char b = 0x9e;      // 即 1001 1110, 相當於 b = 158 

	// 試用 AND 運算子，得到 c = 0x8c 即 1000 1100
	unsigned char c = a & b;
	printf("%x AND %x = %x\n", a, b, c);

	// 試用 OR  運算子，得到 c = 0xdf 即 1101 1111
	c = a | b;
	printf("%x OR %x = %x\n", a, b, c);

	// 試用 XOR 運算子，得到 c = 0x53 即 0101 0011
	c = a ^ b;
	printf("%x XOR %x = %x\n", a, b, c);

	// 試用 NOT 運算子，得到 c = 0x32 即 0011 0010
	c = ~a;
	printf("NOT %x = %x\n", a, c);
}
