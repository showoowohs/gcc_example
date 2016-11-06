#include <stdio.h>
#include <string.h>

int char_to_int(char* input){
	char* s = input;
	char* num_ptr = s;

	while(*num_ptr < '0' || *num_ptr > '9')
		++num_ptr;

	int number = atoi(num_ptr);

	return number;
}

int main(int argc, char *argv[])
{
	char *input;
	int input_number;
	// check val
	if(argc == 2){
		input = argv[1];	
		// check whether negative
		if(strstr(input, ".")){
			printf("%s is not a integer(need non-negative)\n", input);
			goto print_err;
		}
		input_number = char_to_int(input);

		// print decimal
		printf("your input decimal is %d\n", input_number);
		// print hexadecimal
		printf("hexadecimal is %x\n", input_number);
	}else{
print_err:
		input = "please input correct value\nsugges val is a number(decimal), we will transfrom to hexadecimal\nexample: ./DecToHex 15\n";
		printf("%s", input);
	}
	return 0;
}

