
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
#define CHUNK 1024 /* read 1024 bytes at a time */
	char buf[CHUNK];
	char copied[CHUNK];
	FILE *file;
#ifdef WRITE
	FILE *file_w;
#endif
	char fn[256];
	char check_repeat[50];
	char last_i2c_cmd[50];

	// Path
	//snprintf(fn, sizeof(fn), "/etc/firmware/tef6638_init.txt");
	//snprintf(fn, sizeof(fn), "6638_0607.txt");
	if(argv[1] == NULL)	
		printf("please input file, ex: parser_tef6638 6638.txt\n");

	snprintf(fn, sizeof(fn), "%s", argv[1]);

	file = fopen(fn, "r");
#ifdef WRITE
	file_w = fopen( "write.txt","w" );
#endif
	if (file) {
		
		while (!feof(file)) 
		{ 
			fgets(buf, sizeof(buf), file);  
			//printf("%s\n", buf);
			// copy buf
			strcpy(copied, buf);
			
			// find I2CW
			// example: XX 03:45:54:I2CW     S C6  F2 42 DB 08 01 P
			if(strstr(copied, "I2CW") != NULL){
				//printf("%s\n", copied);
				
				char tmp[100];
				char one[100];// XX 03:45:54:I2CW
				char two[100];// S C6  F2 42 DB 08 01 P ^M 
				sscanf(copied, "%[^S] %[^,]", one, two);
				//printf("%s\n", one);
				//printf("%s\n", two);

				// save valid i2c cmd
				strcpy(one, two);

				// check format only "S C6 .......... "
				if(strstr(one, "S C0") != NULL){
					//printf("%s\n", one);
					char valid_i2c_cmd[CHUNK];
					sscanf(one, "%[^P]%s", tmp, two);
					//printf("%s\n", tmp);// S C6  F2 42 DB 08 01
					//printf("%s\n", two);// P
					//printf("%s%s\n", tmp, two);

					strncat(tmp, two, sizeof(two));
					//printf("%s\n", tmp);// S C6  F2 42 DB 08 01 P

					sscanf(tmp, "%s %s %[^P]", one, two, last_i2c_cmd);
					//printf("%s\n", last_i2c_cmd);// F2 42 DB 08 01
					
					// check repeat
					if(strncmp(last_i2c_cmd, check_repeat, 50))
						printf("%s\n", last_i2c_cmd);// F2 42 DB 08 01

					//save last i2c cmd( check repeat)
					strcpy(check_repeat, last_i2c_cmd);
#ifdef WRITE
					// write file

					if( file_w != NULL ){
						fwrite(last_i2c_cmd, 1, sizeof(last_i2c_cmd), file_w);
						fwrite("\r\n",2,1,file_w);
					}
#endif

				}
			}
		} 
		fclose(file);
#ifdef WRITE
		fclose(file_w);
#endif
	}
	return 0;
}

