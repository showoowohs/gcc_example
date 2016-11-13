/*
 * copy from http://ccckmit.wikidot.com/cp:macrofunc
 */
#include <stdio.h>

#if !defined(MESSAGE_FROM_MK)
	# error "You have forgotten to define the header file name."
#endif

char *format = "%s",
     *string_from_mk = MESSAGE_FROM_MK;

int main(){
	printf(format, string_from_mk);
}
