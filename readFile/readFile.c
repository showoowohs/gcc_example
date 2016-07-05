#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//#define Benson_Debug

char* load_file(char const* path)
{
	char* buffer = 0;
	long length;
	FILE * f = fopen (path, "rb"); //was "rb"

	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = (char*)malloc ((length+1)*sizeof(char));
		if (buffer)
		{
			fread (buffer, sizeof(char), length, f);
		}
		fclose (f);
	}
	buffer[length+1] = '\0';
	// for (int i = 0; i < length; i++) {
	//     printf("buffer[%d] == %c\n", i, buffer[i]);
	// }
	//printf("buffer = %s\n", buffer);

	return buffer;
}

void CheckVar(int argc){
	if(argc != 3){
		printf("argc value error, argc=%d\n", argc);
		exit(0);
	}
}

int main(int argc, char *argv[]) {

	// 0. check value
	CheckVar(argc);

	char * PATH1 = argv[1];
	char * PATH2 = argv[2];
#ifdef Benson_Debug
	printf("PATH1 = %s\n", PATH1);
	printf("PATH2 = %s\n", PATH2);
#endif


	// 1. read andia_app.mk to tmp
	//char * tmp = load_file("./andia_app.mk");
	char * tmp = load_file(PATH1);

	//printf("buffer = %s\n", tmp);
	
	// 2. read vcm30t30.mk to line 
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	//fp = fopen("./vcm30t30.mk", "r");
	fp = fopen(PATH2, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		//printf("Retrieved line of length %zu :\n", read);
		char * scan = "# Live Wallpapers";
		if(strncmp(line, scan, 10) == 0){

			strcpy(line, tmp);

			//printf("%s\n", line);
		}

		printf("%s", line);

	}

	fclose(fp);

	// 3. write line connect to output.txt

#if 0
	FILE *fptr;
	fptr=fopen("program.txt","w");
	if(fptr==NULL){
		printf("Error!");
		exit(1);
	}
	fprintf(fptr,"%s",line);
	fclose(fptr);
#endif
	return 0;
}
