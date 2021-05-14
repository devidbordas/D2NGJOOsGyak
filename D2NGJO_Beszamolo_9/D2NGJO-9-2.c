#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int fd;
int file;
int main()
{
	fd = open("fifoka", O_RDWR);
	int i=0;
	if(fd<0)
	{
		perror("open");
		exit(-1);
	}
	int ret, check;
	char buffer[80];

    FILE *fp = NULL;
	while (1)
	{
	    fp = fopen("tarolo.txt", "a+");
        ret = read(fd, buffer, 80);
        i++;
		fprintf(fp,"%d ",i);
        fprintf(fp,"%s",buffer);
        fclose(fp);
	}
	close(fd);
	unlink("fifoka");
	return 0;
}
