#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    

int read_port(void)
{
	int fd = open("/dev/ttyHS3", O_RDONLY | O_NOCTTY);
	if (fd == -1)
	{
		/* Could not open the port. */
		perror("open_port: Unable to open /dev/ttyHS3 - ");
	}

	printf("1\n");
	char buffer[255];
	int n = read(fd, buffer, sizeof(buffer));
	printf("2\n");
	if (n < 0)
		fputs("read failed!\n", stderr);
	printf("3\n");
	return (fd);
}

int main() {
#if 0
	char byte;
	//int fd = open("/dev/ttyUSB1", O_RDWR);
	int fd = open("/dev/ttyHS3", O_RDWR);
	write(fd, "X", 1);
	ssize_t size = read(fd, &byte, 1);
	printf("Read byte %c\n", byte);
#else
	read_port();
#endif

	return 0;
}



