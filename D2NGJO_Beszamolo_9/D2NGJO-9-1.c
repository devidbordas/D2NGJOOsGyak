#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
void suicide(int fd);
int fd;
int main()
{
	int ret = mkfifo("fifoka", 00666);
	if(ret<0)
	{
		perror("fed");
		unlink("fifoka");
		exit(-1);
	}
	fd = open("fifoka", O_RDWR);
	if(fd<0)
	{
		perror("open");
		exit(-1);
	}
	int pid=getpid();
	signal(SIGTERM, suicide);
	printf("A pidem: %d.",pid);
	char buffer[80];
	fd = open("fifoka", O_RDWR);
	while(1)
	{
		printf("\nKarakter: ");
		fgets(buffer, (int)sizeof(buffer), stdin);
		ret = write(fd, buffer, strlen(buffer)+1);
		printf("%ld - %s, r: %s\n", ret, strerror(errno), buffer);
		if(ret<0)
		{
			perror("write");
			exit(-1);
		}
	};
	return 0;
}
void suicide(int fd)
{
	close(fd);
	unlink("fifoka");
	exit(0);
}
