#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<argc;i++){
		char *arg=argv[i];

		if(strcmp(arg, "-h")==0 || strcmp(arg,"-?")==0  || argc==1){
			printf("Usage: char_to_ASCLL <string>\n");
			printf("Can input any string, will translate to ASCLL\n");
			printf("          #       example: char_to_ASCLL 1\n");
			printf("\n");
		}else if(i>0){
			int j;
			int len=strlen(arg);
			printf("%s to ASCLL is ", arg);
			for(i = 0; i < len ;i++){
				printf("%d ", arg[i]);
			}
			printf("\n");
		}
	}

}
