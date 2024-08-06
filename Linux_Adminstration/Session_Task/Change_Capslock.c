#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int new_fd;
	new_fd=open("/sys/class/leds/input2::capslock/brightness",O_RDWR);
	char *Zero="0";
	char *One="1";
	char InFileValue;
        FILE *bright=fopen("/sys/class/leds/input2::capslock/brightness","r");
	fscanf(bright," %c ",&InFileValue);
	fclose(bright);
	/*Check my above lines by print the value*/
//	printf("%c\n",InFileValue);
	/*Copying the value to output file in my home directory*/
	FILE *output=fopen("/home/youssef/output","w");
	fprintf(output,"%c",InFileValue);
	fclose(output);
	char RO;
	FILE *readOutput=fopen("/home/youssef/output","r");
	fscanf(readOutput," %c ",&RO);
	printf("%c\n",RO);
	if(RO == '0')
	{
		write(new_fd,One,1);
	}
	else
	{
		write(new_fd,Zero,1);
	}

	return 0;
}
