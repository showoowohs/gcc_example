#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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

char* load_file2(char const* path)
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
	int i;
	// for (i = 0; i < length; i++) {
	//     printf("buffer[%d] == %c\n", i, buffer[i]);
	// }
	//printf("buffer = %s\n", buffer);

	return buffer;
}

char *string_concat(char *str1, char *str2) {  
	// 計算所需的陣列長度  
	int length=strlen(str1)+strlen(str2)+1;  

	// 產生新的陣列空間  
	char *result = (char*)malloc(sizeof(char) * length);  

	// 複製第一個字串至新的陣列空間  
	strcpy(result, str1);  
	// 串接第二個字串至新的陣列空間  
	strcat(result, str2);  

	return result;  
}  

int main(int argc, char *argv[]) {

	char * tmp = load_file("./andia_app.mk");
	//strcpy(tmp, "# Live Wallpapers");
	//string_concat(tmp,"# Live Wallpapers");

	//printf("buffer = %s\n", tmp);
	
	//load_file2("./andia_app.mk");
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("./vcm30t30.mk", "r");
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

	return 0;
}
