/*
 *  copy from http://catchtest.pixnet.net/blog/post/21869493-linux%E7%A8%8B%E8%A8%AD%E5%AD%B8%E7%BF%92%E7%AD%86%E8%A8%98(%E5%85%AD)
 *  whence: SEEK_SET SEEK_CUR SEEK_END
 */
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	char buf[9];
	int fd;

	// buf size lock 
	fd = open(argv[1], O_RDONLY);
	read(fd,buf,9);
	printf("%s\n", buf);

	// offset chang
	lseek(fd, 60, SEEK_SET);
	read(fd,buf,9);
	printf("%s\n", buf);

	// offset chang
	lseek(fd, 20, SEEK_SET);
	read(fd,buf,9);
	printf("%s\n", buf);

	return 0;

}
